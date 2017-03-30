<%@ Page Language="C#" AutoEventWireup="true" CodeFile="priceOrder.aspx.cs" Inherits="_04_Database_store_Order" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>price Order</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            font-weight: bold;
            font-family: 標楷體;
            font-size: x-large;
            height: 28px;
            text-align: left;
        }
        .auto-style2 {
            height: 28px;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <asp:Label ID="placeLabel" runat="server" Text="Label" CssClass="placeTitle"></asp:Label>
&nbsp;<span class="title">旅遊資訊，請參考</span><br />
        <table>
            <tr>
                <td class="auto-style1">旅行者：&nbsp;&nbsp; </td>
                <td class="auto-style2">
                    <asp:Label ID="userLabel" runat="server" Text="Label" CssClass="userName"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">單價：</td>
                <td class="auto-style2">
                    <asp:Label ID="priceLabel" runat="server" CssClass="tableContent" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">天數:</td>
                <td class="auto-style2">
                    <asp:Label ID="daysLabel" runat="server" CssClass="tableContent" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">總價:</td>
                <td class="auto-style2">
                    <asp:Label ID="totalLabel" runat="server" CssClass="tableContent" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">啟航日：</td>
                <td class="auto-style2">
                    <asp:Label ID="tripDateLabel" runat="server" CssClass="userName" Text="Label"></asp:Label>
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
        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/03_ASP/06_price/priceTrip.aspx">回上頁</asp:HyperLink>

    </div>
        <p>
            &nbsp;</p>
        <asp:HiddenField ID="youtubeIdHiddenField" runat="server" />
    </form>
</body>
</html>
<script src="../../JavaScript/youtubeOrderJavaScript%20.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>