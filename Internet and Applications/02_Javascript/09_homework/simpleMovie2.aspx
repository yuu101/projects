<%@ Page Language="C#" AutoEventWireup="true" CodeFile="simpleMovie2.aspx.cs" Inherits="_03_ASP_03_HW_INTRO" %>

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
    <p>
        &nbsp;</p>
    <h3 data-bind="text: movieContent.Name" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; font-family: 'Microsoft JhengHei', Arial, Helvetica, Arial, sans-serif; font-weight: normal !important; line-height: 1.1; margin-top: 5px; margin-bottom: 10px; font-size: 24px; text-shadow: none; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">鴿子在樹枝上沈思</h3>
    <h4 data-bind="text: movieContent.ForeignName" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; font-family: 'Microsoft JhengHei', Arial, Helvetica, Arial, sans-serif; font-weight: normal !important; line-height: 1.1; margin-top: 5px; margin-bottom: 10px; font-size: 18px; text-shadow: none; color: rgb(51, 51, 51); font-style: normal; font-variant: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">A Pigeon Sat On A Branch Reflecting On Existence</h4>
    <p data-bind="text: movieContent.Synopsis" style="box-sizing: border-box; border-top-left-radius: 0px !important; border-top-right-radius: 0px !important; border-bottom-right-radius: 0px !important; border-bottom-left-radius: 0px !important; margin: 0px 0px 10px; color: rgb(85, 85, 85); line-height: 24px; font-family: 'Helvetica Neue', Helvetica, Arial, sans-serif; font-size: 15px; font-style: normal; font-variant: normal; font-weight: normal; letter-spacing: normal; orphans: auto; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: auto; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255);">
        全片由39個場景構成，將人類的生活瑣碎經歷誇張化，如同畫作一般將人類的歷史與生活濃縮其中。影片維持他一貫的作者語言：鏡頭如詩如畫又寓意悠遠，情節幽默詩意、蒼白臉孔的角色，但個個特立獨行。片名來自偉大的尼德蘭畫家老勃魯蓋爾的名作「雪中獵人」，這幅畫描繪了一群獵人打獵歸來的場景，畫中的樹枝上停著兩隻黑色鳥兒。</p>
</body>
</html>
<script src="youtubeMediaJavaScript2.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>