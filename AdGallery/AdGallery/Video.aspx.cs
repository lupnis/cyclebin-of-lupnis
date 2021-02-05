using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.OleDb;

namespace AdGallery
{
    public partial class Video : Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Request["Id"]==null|| Request["Id"] =="")
            {
                Response.Redirect("~/AdBrowser");
            }
            else
            {
                OleDbConnection addb = new OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath(@"App_Data\AdList.accdb"));
                OleDbCommand cmd = addb.CreateCommand();
                OleDbConnection addb2 = new OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath(@"App_Data\AdList.accdb"));
                OleDbCommand cmd2 = addb2.CreateCommand();
                try
                {
                    
                    addb.Open();
                    string qcode = "Select * From Ads Where Id = "+ Request["Id"];
                    cmd.CommandText = qcode;
                   
                   OleDbDataReader rdata = cmd.ExecuteReader();
                    string fpath = "";
                    int h = 0;
                    while(rdata.Read())
                    {
                        fpath = rdata[5].ToString();
                        h=int.Parse(rdata[6].ToString());
                        labeltitle.InnerText = rdata[1].ToString();
                       // cholder.InnerHtml = "<h4 style=\"margin-left:auto\">" +  + "</h4>";
                    }
                    if(fpath==""||fpath==null)
                    {
                        loadfield.InnerHtml = "<h4>没有找到这个文件（404）TAT</h4>";
                        addb.Close();
                    }
                    else
                    {
                        loadfield.InnerHtml = "<video style=\"width:90%;height:77vh\" controls=\"\" autoplay=\"\" name=\"media\"><source src=\"" + fpath + "\" type=\"video/mp4\"></video>";
                       addb.Close();
                        
                        qcode = "Update Ads Set P = " + (h+1) + "  Where Id = " + Request["Id"];
                        addb2.Open();
                        cmd2.CommandText = qcode;

                        OleDbDataReader rdata2 = cmd2.ExecuteReader();
                        addb.Close();
                        addb2.Close();
                    }
                }
                catch(Exception ex)
                {
                    addb.Close();
                    addb2.Close();
                    loadfield.InnerHtml += "<h4>数据库挂了，请联系Lupnis来修</h4><br />" + ex.Message + "";
                }
            }
        }
    }
}//this.Page.ClientScript.RegisterClientScriptBlock(this.GetType(), "this", "<script>history.go(-2);</script>");