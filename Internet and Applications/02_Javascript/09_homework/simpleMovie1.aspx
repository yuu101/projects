<%@ Page Language="C#" AutoEventWireup="true" CodeFile="simpleMovie1.aspx.cs" Inherits="_03_ASP_03_HW_INTRO" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>我要看電影</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:ImageButton ID="ImageButton1" runat="server" Height="368px" ImageUrl="http://www.ambassador.com.tw/assets/img/movies/FastFurious701_640x960.jpg" Width="272px" PostBackUrl="~/03_ASP/09_homework/simpleMovie1.aspx" />
        <asp:ImageButton ID="ImageButton2" runat="server" Height="368px" ImageUrl="http://www.ambassador.com.tw/assets/img/movies/APigeonSatOnABranchReflectingOnExistence01_640x960.jpg" Width="272px" PostBackUrl="~/03_ASP/09_homework/simpleMovie2.aspx" />
        <asp:ImageButton ID="ImageButton3" runat="server" Height="368px" ImageUrl="http://www.ambassador.com.tw/assets/img/movies/TheLittleDeath01_640x960.jpg" Width="272px" PostBackUrl="~/03_ASP/09_homework/simpleMovie3.aspx" />
        <br />
        <br />
        <br />
        <div id="player" style="height: 190px; width: 260px">
        </div>
    
    </div>
    </form>
    <div>
        <h3 data-bind="text: movieContent.Name" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; font-family: 'Microsoft JhengHei', Arial, Helvetica, Arial, sans-serif; font-weight: normal !important; line-height: 1.1; margin-top: 5px; margin-bottom: 10px; font-size: 24px; text-shadow: none; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">玩命關頭7</h3>
        <h4 data-bind="text: movieContent.ForeignName" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; font-family: 'Microsoft JhengHei', Arial, Helvetica, Arial, sans-serif; font-weight: normal !important; line-height: 1.1; margin-top: 5px; margin-bottom: 10px; font-size: 18px; text-shadow: none; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">Fast &amp; Furious 7</h4>
        <p data-bind="text: movieContent.Synopsis" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; margin: 0px 0px 10px; color: rgb(85, 85, 85); line-height: 24px; font-family: 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 15px; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">
            《玩命關頭7》由導演溫子仁首度執導，還有觀眾喜愛的蜜雪兒羅卓奎茲、喬丹娜布魯斯特、泰瑞斯吉布森、路達克里斯、艾兒莎巴塔奇、盧卡斯布萊克以及新加入的角色包括傑森史塔森、吉蒙翰蘇、東尼嘉、龍達魯西和寇特羅素。尼爾莫瑞茲、馮迪索和麥可佛瑞爾參與幕後製片，克里斯摩根為此片編劇。</p>
    </div>
</body>
</html>
<script src="youtubeMediaJavaScript1.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>