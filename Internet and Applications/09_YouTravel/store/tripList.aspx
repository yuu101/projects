<%@ Page Language="C#" AutoEventWireup="true" CodeFile="tripList.aspx.cs" Inherits="_09_YouTravel_store_tripList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Trip List</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />


</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div>
            <span class="title">旅遊列表<br />
            </span>
            <br />
            <table >
                <tr>
                    <td>旅行者：</td>
                    <td>
                        <asp:Label ID="userLabel" runat="server" Text="Label"></asp:Label>
                    </td>
                </tr>
            </table>
            <br />
            <asp:GridView ID="tripListGridView" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="tripId" DataSourceID="tripSqlDataSource" ForeColor="#333333" GridLines="None" PageSize="5">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="tripId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="tripId" />
                    <asp:BoundField DataField="place" HeaderText="地點" SortExpression="place" />
                    <asp:BoundField DataField="days" HeaderText="天數" SortExpression="days" />
                    <asp:BoundField DataField="total" DataFormatString="{0:N0}" HeaderText="總價" SortExpression="total" />
                    <asp:BoundField DataField="tripDate" DataFormatString="{0:d}" HeaderText="啟航日" SortExpression="tripDate" />
                </Columns>
                <EditRowStyle BackColor="#2461BF" />
                <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
                <RowStyle BackColor="#EFF3FB" />
                <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
                <SortedAscendingCellStyle BackColor="#F5F7FB" />
                <SortedAscendingHeaderStyle BackColor="#6D95E1" />
                <SortedDescendingCellStyle BackColor="#E9EBEF" />
                <SortedDescendingHeaderStyle BackColor="#4870BE" />
            </asp:GridView>
            <br />
            <asp:SqlDataSource ID="tripSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT trip.tripId, tour.place, trip.days, trip.total, trip.tripDate FROM tour INNER JOIN trip ON tour.tourId = trip.tourId WHERE (trip.userName = @userName) ORDER BY trip.tripDate DESC, trip.days DESC">
                <SelectParameters>
                    <asp:SessionParameter Name="userName" SessionField="userName" />
                </SelectParameters>
            </asp:SqlDataSource>
            <br />
            <br />
            <br />
            <br />
        </div>
    
    </div>
    </form>
</body>
</html>
