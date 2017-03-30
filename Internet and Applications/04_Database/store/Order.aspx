<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Order.aspx.cs" Inherits="_04_Database_store_Order" %>

<!DOCTYPE html>
<script runat="server">


</script>


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
        <asp:Button ID="orderButton" runat="server" OnClick="orderButton_Click" Text="訂購" />
        &nbsp;&nbsp;&nbsp;
        <br />
        <br />
        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/03_ASP/06_price/priceTrip.aspx">回上頁</asp:HyperLink>

    </div>
        <p>
            &nbsp;</p>
        <asp:HiddenField ID="youtubeIdHiddenField" runat="server" />
        <asp:HiddenField ID="totalHiddenField" runat="server" />
        <asp:SqlDataSource ID="tripSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [trip] WHERE [tripId] = @tripId" InsertCommand="INSERT INTO [trip] ([userName], [tourId], [days], [total], [tripDate]) VALUES (@userName, @tourId, @days, @total, @tripDate)" SelectCommand="SELECT * FROM [trip]" UpdateCommand="UPDATE [trip] SET [userName] = @userName, [tourId] = @tourId, [days] = @days, [total] = @total, [tripDate] = @tripDate WHERE [tripId] = @tripId">
            <DeleteParameters>
                <asp:Parameter Name="tripId" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:SessionParameter Name="userName" SessionField="userName" Type="String" />
                <asp:SessionParameter Name="tourId" SessionField="tourId" Type="Int32" />
                <asp:SessionParameter Name="days" SessionField="days" Type="Int32" />
                <asp:SessionParameter Name="total" SessionField="totalHiddenField" Type="Int32" />
                <asp:SessionParameter Name="tripDate" SessionField="tripDate" Type="DateTime" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="userName" Type="String" />
                <asp:Parameter Name="tourId" Type="Int32" />
                <asp:Parameter Name="days" Type="Int32" />
                <asp:Parameter Name="total" Type="Int32" />
                <asp:Parameter Name="tripDate" Type="DateTime" />
                <asp:Parameter Name="tripId" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
        <br />
        <br />
    </form>
</body>
</html>
<script src="../../JavaScript/youtubeOrderJavaScript%20.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>