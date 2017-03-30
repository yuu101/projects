<%@ Page Language="C#" AutoEventWireup="true" CodeFile="25_pollDataList.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_25_pollDataList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>total</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .新增樣式1 {
        }
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">最美的季節&nbsp; 票數統計</span><br />
        <br />
        <asp:DataList ID="pollDataList" runat="server" CellPadding="4" DataSourceID="seasonSqlDataSource" ForeColor="#333333" Height="167px" Width="247px" RepeatDirection="Horizontal">
            <AlternatingItemStyle BackColor="White" />
            <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <ItemStyle BackColor="#EFF3FB" />
            <ItemTemplate>
                <asp:Label ID="seasonLabel" runat="server" Text='<%# Eval("season") %>' />
                <br />
                <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
<br />
                <table class="auto-style1">
                    <tr>
                        <td>票數：</td>
                        <td>
                            <asp:Label ID="Expr1Label" runat="server" Text='<%# Eval("Expr1") %>' />
                        </td>
                    </tr>
                </table>
                <br />
            </ItemTemplate>
            <SelectedItemStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
        </asp:DataList>
        <br />
        <br />
        <br />
        <br />
        <asp:SqlDataSource ID="seasonSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT COUNT(poll.seasonId) AS Expr1, poll.seasonId AS Expr2, season.season, season.flickrId FROM poll INNER JOIN season ON poll.seasonId = season.seasonId GROUP BY poll.seasonId, season.season, season.flickrId"></asp:SqlDataSource>
        <br />
        <br />
        <br />
    
    </div>
    </form>
</body>
</html>
