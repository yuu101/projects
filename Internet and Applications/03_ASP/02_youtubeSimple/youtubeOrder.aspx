<%@ Page Language="C#" AutoEventWireup="true" CodeFile="youtubeOrder.aspx.cs" Inherits="_03_ASP_02_youtube_youtubeOrder" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Youtube Order</title>
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
    &nbsp;<br />
        <br />
        <div id="player">
        </div>
&nbsp;&nbsp;
         <br />
        <br />
        <br />
        &nbsp;&nbsp;
        &nbsp;&nbsp;&nbsp;
        <br />
        <br />
        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/03_ASP/03_image/imageTrip.aspx">回上頁</asp:HyperLink>

    </div>
        <p>
            &nbsp;</p>
        <asp:HiddenField ID="youtubeIdHiddenField" runat="server" />
    </form>
</body>
</html>
<script src="../../JavaScript/youtubeOrderJavaScript%20.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>