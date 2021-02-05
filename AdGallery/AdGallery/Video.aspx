<%@ Page Title="视频" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Video.aspx.cs" Inherits="AdGallery.Video" %>


<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <hr />
    <div class="mdl-grid">
    <button id="backbtn" class="mdl-button mdl-js-button mdl-button--raised" type="button">&laquo;返回</button> 
        <label style="text-align:center;width:90%;font-size:20px" runat="server" id="labeltitle"></label>
        
        </div>
<script>
    (function () {
        'use strict';
        var backButton = document.querySelector('#backbtn');
        var handler = function (event) {
            showSnackbarButton.style.backgroundColor = '';
        };
        backButton.addEventListener('click', function () {
            'use strict';
            window.history.back();
        });
    }());
</script>
    <hr />
    <pre runat="server" id="loadfield" style="margin-left:auto;margin-right:auto;text-align:center">
        <div runat="server" id="loadbar" class="mdl-spinner mdl-js-spinner is-active" style="margin-left: auto; margin-right: auto"></div>
        </pre>
</asp:Content>
