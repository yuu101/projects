<%@ Page Language="C#" AutoEventWireup="true" CodeFile="wsStreetView.aspx.cs" Inherits="_08_GoogleMap_wsStreetView" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>wsStreetView</title>
    <link href="../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">web service 街景服務</span><br />
        <br />
        <asp:RadioButtonList ID="placeRadioButtonList" runat="server" DataSourceID="placeSqlDataSource" DataTextField="place" DataValueField="tourId" OnDataBinding="placeRadioButtonList_DataBinding" RepeatDirection="Horizontal" AutoPostBack="True">
        </asp:RadioButtonList>
        <br />
        <div id="streetViewCanvas" style="width: 400px; height: 300px">
        </div>
        <br />
        <asp:SqlDataSource ID="placeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT [tourId], [place] FROM [tour]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
<script src="../JavaScript/wsStreetViewJQuery.js"></script>
<script src="../JavaScript/LocationService.js"></script>
<script src="../Scripts/jquery-1.10.2.js"></script>
<script src="http://maps.googleapis.com/maps/api/js?v=3.19&sensor=false"></script>