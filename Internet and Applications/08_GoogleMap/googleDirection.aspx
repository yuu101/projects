<%@ Page Language="C#" AutoEventWireup="true" CodeFile="googleDirection.aspx.cs" Inherits="_08_GoogleMap_googleDirection" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>googleDirection</title>
    <link href="../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">google 導航與街景</span><br />
        <br />
        <asp:RadioButtonList ID="placeRadioButtonList" runat="server" DataSourceID="placeSqlDataSource" DataTextField="place" DataValueField="tourId" OnDataBinding="placeRadioButtonList_DataBinding" RepeatDirection="Horizontal" AutoPostBack="True">
        </asp:RadioButtonList>
        <table class="auto-style1">
            <tr>
                <td colspan="2">
                    <asp:Image ID="placeImage" runat="server" />
                </td>
            </tr>
            <tr>
                <td>
        <div id="mapCanvas" style="width: 400px; height: 300px">
        </div>
                </td>
                <td>
                    <div id="streetViewCanvas" style="width: 400px; height: 300px">
                    </div>
                </td>
            </tr>
        </table>
        <br />
        <asp:Label ID="distanceLabel" runat="server"></asp:Label>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="durationLabel" runat="server"></asp:Label>
        <br />
        <asp:SqlDataSource ID="placeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT [tourId], [place] FROM [tour]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
<script src="../JavaScript/googleDirectionJQuery.js"></script>
<script src="../JavaScript/LocationService.js"></script>
<script src="../Scripts/jquery-1.10.2.js"></script>
<script src="http://maps.googleapis.com/maps/api/js?v=3.19&sensor=false"></script>