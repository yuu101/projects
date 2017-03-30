<%@ Page Language="C#" AutoEventWireup="true" CodeFile="simpleOrder.aspx.cs" Inherits="_03_ASP_01_simple_simpleOrder" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Simple Order</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <asp:Label ID="placeLabel" runat="server" Text="Label" CssClass="placeTitle"></asp:Label>
&nbsp;<span class="title">旅遊資訊，請參考</span><br />
        <table>
            <tr>
                <td class="userName">旅行者：&nbsp;&nbsp; </td>
                <td>
                    <asp:Label ID="userLabel" runat="server" Text="Label" CssClass="userName"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
    <embed id="tripMediaPlayer" runat="server"  height="132" width="176" showcontrols="0" class="body" />
        <br />
        <br />
        <input id="playButton" type="button" value="播放" onclick="return playButton_onclick()" />
        <input id="pauseButton" type="button" value="暫停"onclick="return pauseButton_onclick()" />
        <input id="stopButton" type="button" value="停止" onclick="return stopButton_onclick()"/>
         <br />
        <br />
        <br />
        &nbsp;&nbsp;
        &nbsp;&nbsp;&nbsp;
        <br />
        <br />
        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/03_ASP/01_simple/simpleTrip.aspx">回上頁</asp:HyperLink>

    </div>
    </form>
</body>
</html>
<script src="../../JavaScript/tripMediaJavascript.js"></script>
