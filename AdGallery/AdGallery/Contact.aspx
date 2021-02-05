<%@ Page Title="联系我们" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Contact.aspx.cs" Inherits="AdGallery.Contact" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
      

    <h4>这还是一个没有开发完毕的网站，如果您有什么建议或者吐槽，请联系我</h4>
    <pre style="margin-left:auto;margin-right:auto;padding-left:15px;padding-right:15px;padding-top:10px">
        <h6>邮箱-不常看：<a href="mailto:Lupnis@outlook.com">Lupnis@outlook.com</a>
        QQ号：<a id="qq">2016626277</a></h6> <button id="demo-show-snackbar" class="mdl-button mdl-js-button mdl-button--raised" type="button">复制QQ号（这个按钮是坏的，麻烦自己复制一下QQ啦：) ）</button>
<div id="demo-snackbar-example" class="mdl-js-snackbar mdl-snackbar">
  <div class="mdl-snackbar__text"></div>
     <button class="mdl-snackbar__action" type="button"></button>
</div>
   <script>
       (function () {
           //'use strict';
           var snackbarContainer = document.querySelector('#demo-snackbar-example');
           var showSnackbarButton = document.querySelector('#demo-show-snackbar');
           var handler = function (event) {
               // showSnackbarButton.style.backgroundColor = '';
           };
           showSnackbarButton.addEventListener('click', function () {
               'use strict';
               showSnackbarButton.style.backgroundColor = '#' +
                   Math.floor(Math.random() * 0xFFFFFF).toString(16);
              
              
               var data = {
                   message: '复制并不成功！',
                   timeout: 2000,
                   actionHandler: handler,
                   actionText: '确定'
               };
               snackbarContainer.MaterialSnackbar.showSnackbar(data);




           });
       }());

       /*
               */
</script> 
        </pre>
</asp:Content>
