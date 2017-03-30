<%@ Page Language="C#" AutoEventWireup="true" CodeFile="32_pollGrid2.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_32_pollGrid2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>result2</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div>
            <span class="title">最美的季節 投票列表<br />
            </span>
            <br />
            <asp:GridView ID="pollGridView" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="pollId" DataSourceID="pollSqlDataSource" ForeColor="#333333" GridLines="None">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="pollId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="pollId" />
                    <asp:BoundField DataField="season" HeaderText="季節" SortExpression="season" />
                    <asp:BoundField DataField="pollTime" HeaderText="投票時間" SortExpression="pollTime" />
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
            <br />
            <asp:SqlDataSource ID="pollSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT season.season, poll.pollId, poll.pollTime FROM poll INNER JOIN season ON poll.seasonId = season.seasonId ORDER BY poll.pollId DESC"></asp:SqlDataSource>
        </div>
    
    </div>
    </form>
</body>
</html>
