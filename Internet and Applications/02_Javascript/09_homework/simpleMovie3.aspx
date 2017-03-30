<%@ Page Language="C#" AutoEventWireup="true" CodeFile="simpleMovie3.aspx.cs" Inherits="_03_ASP_03_HW_INTRO" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
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
        <h3 data-bind="text: movieContent.Name" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; font-family: 'Microsoft JhengHei', Arial, Helvetica, Arial, sans-serif; font-weight: normal !important; line-height: 1.1; margin-top: 5px; margin-bottom: 10px; font-size: 24px; text-shadow: none; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">愛愛小確性</h3>
        <h4 data-bind="text: movieContent.ForeignName" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; font-family: 'Microsoft JhengHei', Arial, Helvetica, Arial, sans-serif; font-weight: normal !important; line-height: 1.1; margin-top: 5px; margin-bottom: 10px; font-size: 18px; text-shadow: none; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">The Little Death</h4>
        <p data-bind="text: movieContent.Synopsis" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; margin: 0px 0px 10px; color: rgb(85, 85, 85); line-height: 24px; font-family: 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 15px; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">
            感情穩定的梅芙，一心想體驗被性侵的感覺，深愛她的男友費盡心思想讓她身歷其境，未料某天真遇到強暴犯；醫生要伊薇和老公玩角色扮演重燃性趣，結果老公渾身戲胞、越演越烈，影帝級的專業表現常讓伊薇招架不住；和老公拼做人的羅薇娜對性事非常冷感，在某次看到老公落淚時竟春心蕩漾，於是千方百計要讓老公傷心哭泣；嘮叨又強勢的老婆總讓菲爾倒陽，他只能在老婆沉睡時偷偷下手，最後乾脆天天餵老婆安眠藥，劑量與日俱增；為聾啞人士翻譯電話的莫妮卡，某天夜裡接到視訊來電，沒想到對方要她撥打成人熱線，讓清純的她陷入窘境。</p>
    </div>
</body>
</html>
<script src="youtubeMediaJavaScript3.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>