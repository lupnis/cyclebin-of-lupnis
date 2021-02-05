using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Windows;
using System.Data;
using System.Data.OleDb;
using System.Text;

namespace AdGallery
{
    public partial class AdBrowser : Page
    {
        string filterkey;
        struct DataCard
        {
            public string title;
            public string type;
            public string hoverimg;
            public string description;
            public string path;
            public int priority;
        };
        private void PullData(string keywords, string filter)
        {
            keywords = System.Web.HttpUtility.UrlDecode(keywords);
            OleDbConnection addb = new OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath(@"App_Data\AdList.accdb"));
            OleDbCommand cmd = addb.CreateCommand();
            try
            {
                addb.Open();
                keywords.Replace(@"=", "");/*这一段挺恶心的，不是吗:P*/
                keywords.Replace(@"!", "");
                keywords.Replace(@"?", "");
                keywords.Replace(@"~", "");
                keywords.Replace(@"/", "");
                keywords.Replace(@"\", "");
                keywords.Replace(@"<", "");
                keywords.Replace(@">", "");
                keywords.Replace(@".", "");
                keywords.Replace(@"{", "");
                keywords.Replace(@"}", "");
                keywords.Replace(@"\", "");
                keywords.Replace(@"|", "");
                keywords.Replace(@"\", "");
                keywords.Replace(@"[", "");
                keywords.Replace(@"]", "");
                keywords.Replace(@":", "");
                keywords.Replace(@"`", "");
                string qcode = "Select * From Ads ";
                int idcode = 0;

                if (int.TryParse(keywords, out idcode))
                {
                    qcode += "Where Id = " + idcode;
                }
                else
                {
                    if ((filter == "All" && keywords == "") || (filter == "" && keywords == ""))
                    {
                        qcode = "Select * From Ads ";
                    }
                    else
                    {
                        if (filter == "All")
                        {
                            qcode += "Where Title Like \'%" + keywords + "%\' Or Description Like \'%" + keywords + "%\' ";
                        }
                        else if (keywords == "")
                        {
                            qcode += "Where " +
                               (filter.Contains("Common") ? "Type Like \'%Common\'" : "Id = -1 ") +
                               (filter.Contains("Food") ? " Or Type Like \'%Food\'" : " Or Id = -1 ") +
                               (filter.Contains("GNC") ? " Or Type Like \'%GNC\'" : " Or Id = -1 ") +
                               (filter.Contains("Literary") ? " Or Type Like \'%Literary\'" : " Or Id = -1 ") +
                               (filter.Contains("Software") ? " Or Type Like \'%Software\'" : " Or Id = -1 ");
                        }
                        else
                        {

                            qcode += "Where ( " +
                               (filter.Contains("Common") ? "Type Like \'%Common\'" : "Id = -1 ") +
                               (filter.Contains("Food") ? " Or Type Like \'%Food\'" : " Or Id = -1") +
                               (filter.Contains("GNC") ? " Or Type Like \'%GNC\'" : " Or Id = -1 ") +
                               (filter.Contains("Literary") ? " Or Type Like \'%Literary\'" : " Or Id = -1 ") +
                               (filter.Contains("Software") ? " Or Type Like \'%Software\'" : " Or Id = -1 ")
                               + " ) And ( Title Like \'%" +
                               keywords + "%\' Or Description Like \'%" +
                               keywords + "%\' )";
                        }
                    }
                }
                cmd.CommandText = qcode;
                OleDbDataReader rdata = cmd.ExecuteReader();
                Dictionary<int, DataCard> returndata = new Dictionary<int, DataCard>();
                while (rdata.Read())
                {
                    DataCard dvalue = new DataCard();
                    dvalue.title = rdata[1].ToString();
                    dvalue.type = rdata[2].ToString();
                    dvalue.hoverimg = rdata[3].ToString();
                    dvalue.description = rdata[4].ToString();
                    dvalue.path = rdata[5].ToString();
                    dvalue.priority = int.Parse(rdata[6].ToString());
                    returndata.Add(int.Parse(rdata[0].ToString()), dvalue);
                }

                if (returndata.Count == 0)
                {
                    cardgrid.InnerHtml = "<pre style=\"text-align:center;margin-left:auto;margin-right:auto\"><h4>未找到数据，请检查一下下QAQ</h4></pre>";
                }
                else
                {
                    var sortedr = returndata.OrderByDescending(i => i.Value.priority);
                    foreach (var item in sortedr)
                    {
                        string card = "<div style=\"padding-left:5px;padding-right:5px;padding-bottom:5px\"><div class=\"mdl-shadow--2dp\" style=\"width: 450px\">" +
                                      "<div style=\"color: #ccc;height: 200px;background: url(\'" + item.Value.hoverimg + "\') center / cover;\">" +
                                      "<h2 class=\"mdl-card__title-text\" style=\"background-color:rgba(100,100,100,.8);padding-left:10px;padding-right:10px\" runat=\"server\" id=\"card_title\">" +
                                      item.Value.title +
                                      "</h2></div><div class=\"mdl-card__supporting-text\" runat=\"server\" id=\"card_description\">" +
                                      item.Value.description +
                                      "</div>" +
                                      "<div class=\"mdl-card__actions mdl-card--border\">" +
                                      " <a runat=\"server\" href=\"" +
                                     ( item.Value.type.Contains("N-") ? item.Value.path: "Video?Id=" + item.Key) +
                                     
                                      "\" class=\"mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect\">"+
                                      (item.Value.type.Contains("N-") ?"访问广告链接":"浏览和下载这个视频")
                                      +" &raquo;</a></div></div></div>";
                        cardgrid.InnerHtml += card;
                    }
                }
                loadbar.Visible = false;
                addb.Close();
            }
            catch(Exception ex)
            {
                addb.Close();
                cardgrid.InnerHtml = "<pre style=\"text-align:center;margin-left:auto;margin-right:auto\"><h4>数据库挂了，请联系江修来修</h4><br />"+ex.Message+"</pre>";
            }
        }

        private void CheckDealer()
        {
            CheckBox_f_common.Checked = false;
            CheckBox_f_food.Checked = false;
            CheckBox_f_gnc.Checked = false;
            CheckBox_f_literary.Checked = false;
            CheckBox_f_software.Checked = false;
            if (filterkey == "All")
            {
                CheckBox_f_common.Checked = true;
                CheckBox_f_food.Checked = true;
                CheckBox_f_gnc.Checked = true;
                CheckBox_f_literary.Checked = true;
                CheckBox_f_software.Checked = true;
            }
            else
            {
                foreach (string value in filterkey.Split(';'))
                {

                    switch (value.Trim())
                    {
                        case "Common":

                            CheckBox_f_common.Checked = true;
                            break;
                        case "Food":

                            CheckBox_f_food.Checked = true;
                            break;
                        case "GNC":
                            CheckBox_f_gnc.Checked = true;
                            break;
                        case "Literary":
                            CheckBox_f_literary.Checked = true;
                            break;
                        case "Software":
                            CheckBox_f_software.Checked = true;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Page.IsPostBack)
            {
                if (CheckBox_f_common.Checked && CheckBox_f_food.Checked && CheckBox_f_gnc.Checked && CheckBox_f_literary.Checked && CheckBox_f_software.Checked)
                {
                    filterkey = "All";
                }

                else
                {
                    filterkey = (CheckBox_f_common.Checked ? "Common;" : null) +
                        (CheckBox_f_food.Checked ? "Food;" : null) +
                        (CheckBox_f_gnc.Checked ? "GNC;" : null) +
                        (CheckBox_f_literary.Checked ? "Literary;" : null) +
                        (CheckBox_f_software.Checked ? "Software" : null);
                }
                Response.Redirect("~/AdBrowser?KW=" + System.Web.HttpUtility.UrlEncode(searchbox.Value) + "&Filter=" + System.Web.HttpUtility.UrlEncode(filterkey));
            }
            else
            {
                searchbox.Value = System.Web.HttpUtility.UrlDecode(Request["KW"]);
                filterkey = Request["Filter"] == null ? "All" : System.Web.HttpUtility.UrlDecode(Request["Filter"]);
                CheckDealer();
            }

            PullData(searchbox.Value.ToString(), filterkey);
        }


    }
}






