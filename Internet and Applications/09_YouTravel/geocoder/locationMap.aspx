<%@ Page Language="C#" AutoEventWireup="true" CodeFile="locationMap.aspx.cs" Inherits="_09_YouTravel_geocoder_locationMap" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>locationMap</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">

        .auto-style1 {
            width: 70%;
            height: 124px;
        }
        .auto-style5 {
            width: 112px;
            height: 31px;
        }
        .auto-style6 {
            height: 31px;
        }
        .auto-style3 {
            width: 112px;
            height: 20px;
        }
        .auto-style4 {
            height: 20px;
        }
        .auto-style2 {
            width: 112px;
        }
        </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">Geocoder 地理編碼</span><br />
        <br />
        <table class="auto-style1">
            <tr>
                <td class="auto-style5">查詢：</td>
                <td class="auto-style6">
                    <asp:TextBox ID="addressTextBox" runat="server" Height="18px" Width="264px"></asp:TextBox>
                    &nbsp;<input id="locationButton" onclick="codeAddress();" type="button" value="座標" /></td>
            </tr>
            <tr>
                <td class="auto-style3">經度：</td>
                <td class="auto-style4">
                    <asp:Label ID="lngLabel" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">緯度：</td>
                <td>
                    <asp:Label ID="latLabel" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <div id="mapCanvas" style="width: 400px; height: 300px">
        </div>
    
    </div>
    </form>
</body>
</html>

<script src="../../JavaScript/locationMapJQuery.js"></script>
<script src="../../Scripts/jquery-1.10.2.js"></script>
<script src="http://maps.googleapis.com/maps/api/js?v=3.19&sensor=false"></script>