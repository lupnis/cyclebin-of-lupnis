<%@ Page Title="主页" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="AdGallery._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

    <div class="jumbotron">
        <h1>
            <img src="favicon.ico" width="70" height="70" style="border-radius: 5px" />
            江修的广告中心</h1>
        <p class="lead">江修在2020年8月19号看到了很多广告视频，然后就做了这个网站。里面是各种各样的广告视频。</p>
        <p class="lead">以后可能会有更多的东西。</p>
        <p><a runat="server" href="~/AdBrowser" class="btn btn-primary btn-lg">&nbsp;&nbsp;&nbsp;&nbsp;广告浏览器&nbsp; &raquo;&nbsp;&nbsp;&nbsp;&nbsp;</a></p>
    </div>
    <div class="row">
        <div class="col-md-4">
            <h2>软件</h2>
            <hr />
            <p style="font-size:18px">包括从过去（非常过去）的广告到现在的一些广告</p>
            <p>
                <a runat="server" class="btn btn-default" style="font-size:18px" href="~/AdBrowser?Filter=Software">了解更多 &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>食品</h2>
            <hr />
            <p style="font-size:18px">三年六班李子明</p>
            <p>
                <a runat="server" class="btn btn-default" style="font-size:18px" href="~/AdBrowser?Filter=Food">了解更多 &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>保健品</h2>
            <hr />
            <p style="font-size:18px" >他好，我也好</p>
            <p>
                <a runat="server" class="btn btn-default" style="font-size:18px" href="~/AdBrowser?Filter=GNC">了解更多 &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>一般商品</h2>
            <hr />
            <p style="font-size:18px" >足力健老人鞋</p>
            <p>
                <a runat="server" class="btn btn-default" style="font-size:18px" href="~/AdBrowser?Filter=Common">了解更多 &raquo;</a>
            </p>
        </div>
        <div runat="server" class="col-md-4">
            <h2>小说</h2>
            <hr />
            <p style="font-size:18px" >just do it</p>
            <p>
                <a runat="server" class="btn btn-default" style="font-size:18px" href="~/AdBrowser?Filter=Literary">了解更多 &raquo;</a>
            </p>
        </div>
        <div class="col-md-4">
            <h2>更多分类</h2>
            <hr />
            <p style="font-size:18px" >江修还在想，不定时更新</p>
        </div>
    </div>

</asp:Content>
