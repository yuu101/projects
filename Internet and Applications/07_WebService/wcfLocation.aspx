<%@ Page Language="C#" AutoEventWireup="true" CodeFile="wcfLocation.aspx.cs" Inherits="_07_WebService_wcfLocation" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>wcfLocation</title>
    <link href="../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            height: 16px;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">ScriptManager WCF AJAX 網頁</span><br />
        <br />
        <asp:ScriptManager ID="ScriptManager1" runat="server">
            <Services>
                <asp:ServiceReference path="~/WebServices/LocationService.svc"/>
            </Services>
        </asp:ScriptManager>
        <br />
        <asp:RadioButtonList ID="placeRadioButtonList" runat="server" DataSourceID="placeSqlDataSource" DataTextField="place" DataValueField="tourId" OnDataBound="placeRadioButtonList_DataBound">
        </asp:RadioButtonList>
        <br />
        <table class="auto-style1">
            <tr>
                <td colspan="2">
                    <asp:Image ID="placeImage" runat="server" />
                </td>
            </tr>
            <tr>
                <td class="auto-style2">經度: </td>
                <td class="auto-style2">
                    <asp:Label ID="longitudeLabel" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td>緯度: </td>
                <td>
                    <asp:Label ID="latitudeLabel" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <div id="player">
        </div>
        <br />
        <br />
        <br />
        <asp:SqlDataSource ID="placeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT [tourId], [place] FROM [tour]"></asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
<script src="../JavaScript/wcfJavaScript.js"></script>
<script src="../JavaScript/youtubeJavaScript%20.js"></script>
<script type="text/javascript" src="https://www.youtube.com/iframe_api"></script>