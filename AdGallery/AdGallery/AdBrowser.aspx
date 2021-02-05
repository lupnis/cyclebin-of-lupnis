<%@ Page Title="广告浏览器" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="AdBrowser.aspx.cs" Inherits="AdGallery.AdBrowser" %>


<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <form action="#" style="width: 95%; padding-left: 15px; text-align: center">
        <div runat="server" class="mdl-textfield mdl-js-textfield" style="width: 90%">
            <input runat="server" class="mdl-textfield__input" type="text" id="searchbox" style="width: 98%">
            <label runat="server" class="mdl-textfield__label" for="searchbox" style="width: 98%">输入搜索信息</label>
        </div>
        <asp:Button ID="button_search" runat="server" Text="搜索" class="mdl-button mdl-js-button mdl-button--raised" Style="padding-left: 15px" Width="8%" />
    </form>
    <div>
        <asp:Label ID="label1" runat="server" Text="广告分类："></asp:Label>
        <asp:CheckBox ID="CheckBox_f_software" runat="server" Text="&nbsp;软件" Checked="true" CausesValidation="True" AutoPostBack="True" />
        <asp:CheckBox ID="CheckBox_f_food" runat="server" Text="&nbsp;食品" Checked="true" CausesValidation="True" AutoPostBack="True" />
        <asp:CheckBox ID="CheckBox_f_gnc" runat="server" Text="&nbsp;保健品" Checked="true" CausesValidation="True" AutoPostBack="True" />
        <asp:CheckBox ID="CheckBox_f_common" runat="server" Text="&nbsp;一般商品" Checked="true" CausesValidation="True" AutoPostBack="True" />
        <asp:CheckBox ID="CheckBox_f_literary" runat="server" Text="&nbsp;小说" Checked="true" CausesValidation="True" AutoPostBack="True" />
    </div>

    <hr />
        <div class="mdl-grid" runat="server" id="cardgrid" style="margin-left:auto;margin-right:auto">          
        </div>
        <div runat="server" id="loadbar" class="mdl-spinner mdl-js-spinner is-active" style="margin-left: auto; margin-right: auto"></div>
</asp:Content>
