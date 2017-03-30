<%@ Page Language="C#" AutoEventWireup="true" CodeFile="40_pollGrid3.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_40_pollGrid3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>result3</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <div>
            <span class="title">最美的季節 投票列表</span><br />
            <br />
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="Expr2" DataSourceID="totalSqlDataSource" ForeColor="#333333" GridLines="None">
                <AlternatingRowStyle BackColor="White" />
                <Columns>
                    <asp:BoundField DataField="seasonId" HeaderText="序號" SortExpression="seasonId" />
                    <asp:BoundField DataField="season" HeaderText="季節" SortExpression="season" />
                    <asp:BoundField DataField="Expr1" HeaderText="總票數" ReadOnly="True" SortExpression="Expr1" />
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
            <asp:FormView ID="FormView1" runat="server" CellPadding="4" DataKeyNames="Expr2" DataSourceID="totalSqlDataSource" ForeColor="#333333" Height="16px" Width="221px">
                <EditItemTemplate>
                    Expr1:
                    <asp:TextBox ID="Expr1TextBox" runat="server" Text='<%# Bind("Expr1") %>' />
                    <br />
                    season:
                    <asp:TextBox ID="seasonTextBox" runat="server" Text='<%# Bind("season") %>' />
                    <br />
                    seasonId:
                    <asp:TextBox ID="seasonIdTextBox" runat="server" Text='<%# Bind("seasonId") %>' />
                    <br />
                    Expr2:
                    <asp:Label ID="Expr2Label1" runat="server" Text='<%# Eval("Expr2") %>' />
                    <br />
                    <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                    &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                </EditItemTemplate>
                <EditRowStyle BackColor="#2461BF" />
                <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                <InsertItemTemplate>
                    Expr1:
                    <asp:TextBox ID="Expr1TextBox" runat="server" Text='<%# Bind("Expr1") %>' />
                    <br />
                    season:
                    <asp:TextBox ID="seasonTextBox" runat="server" Text='<%# Bind("season") %>' />
                    <br />
                    seasonId:
                    <asp:TextBox ID="seasonIdTextBox" runat="server" Text='<%# Bind("seasonId") %>' />
                    <br />

                    <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                    &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                </InsertItemTemplate>
                <ItemTemplate>
                    <table class="auto-style1">
                        <tr>
                            <td>最美的季節：</td>
                            <td>
                                <asp:Label ID="seasonLabel" runat="server" Text='<%# Bind("season") %>' />
                            </td>
                        </tr>
                        <tr>
                            <td>得票數：</td>
                            <td>
                                <asp:Label ID="Expr1Label" runat="server" Text='<%# Bind("Expr1") %>' />
                            </td>
                        </tr>
                    </table>
                    <br />
                    &nbsp;<br />
                    <br />
                    <br />
                </ItemTemplate>
                <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />
                <RowStyle BackColor="#EFF3FB" />
            </asp:FormView>
            <br />
            <br />
            <br />
            <asp:SqlDataSource ID="totalSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT COUNT(poll.seasonId) AS Expr1, season.season, poll.seasonId, season.seasonId AS Expr2 FROM poll INNER JOIN season ON poll.seasonId = season.seasonId GROUP BY season.season, poll.seasonId, season.seasonId"></asp:SqlDataSource>
        </div>
    
    </div>
    </form>
</body>
</html>
