<%@ Control Language="C#" AutoEventWireup="true" CodeBehind="ViewSwitcher.ascx.cs" Inherits="AdGallery.ViewSwitcher" %>
<div id="viewSwitcher">
    <%: CurrentView %> ��ͼ | <a href="<%: SwitchUrl %>" data-ajax="false">�л��� <%: AlternateView %></a>
</div>