<%@ Page Language="C#" AutoEventWireup="true" CodeFile="keyBuyers.aspx.cs" Inherits="_10_Facebook_keyBuyers" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>keyBuyers</title>
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
    
        <span class="title">主要顧客排行</span><br />
        <br />
        <table class="auto-style1">
            <tr>
                <td colspan="2">
                    <asp:GridView ID="keyBuyersGridView" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataSourceID="keyBuyersSqlDataSource" ForeColor="#333333" GridLines="None">
                        <AlternatingRowStyle BackColor="White" />
                        <Columns>
                            <asp:BoundField DataField="userName" HeaderText="顧客" SortExpression="userName" />
                            <asp:BoundField DataField="tripCount" HeaderText="旅遊次數" ReadOnly="True" SortExpression="tripCount" />
                            <asp:BoundField DataField="totalSum" DataFormatString="{0:N0}" HeaderText="旅遊總額" ReadOnly="True" SortExpression="totalSum" />
                            <asp:BoundField DataField="daysAvg" HeaderText="平均天數" ReadOnly="True" SortExpression="daysAvg" />
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
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Chart ID="keyBuyersChart" runat="server" DataSourceID="keyBuyersSqlDataSource">
                        <Series>
                            <asp:Series Name="Series1" XValueMember="userName" YValueMembers="totalSum">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="消費金額">
                                </AxisY>
                                <AxisX Title="顧客">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Titles>
                            <asp:Title Name="Title1" Text="消費金額">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
                <td>
                    <asp:Chart ID="keyBuyersPeiChart" runat="server" DataSourceID="keyBuyersSqlDataSource">
                        <Series>
                            <asp:Series ChartType="Pie" IsValueShownAsLabel="True" Legend="Legend1" Name="Series1" XValueMember="userName" YValueMembers="tripCount">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="旅遊次數">
                                </AxisY>
                                <AxisX Title="顧客">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Legends>
                            <asp:Legend Name="Legend1">
                            </asp:Legend>
                        </Legends>
                        <Titles>
                            <asp:Title Name="旅遊人次" Text="旅遊人次">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
            </tr>
            <tr>
                <td colspan="2">
                    <asp:Chart ID="keyBuyersRADARChart" runat="server" DataSourceID="keyBuyersSqlDataSource">
                        <Series>
                            <asp:Series ChartType="Radar" Name="Series1" XValueMember="userName" YValueMembers="daysAvg">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="平均天數">
                                </AxisY>
                                <AxisX Title="顧客">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Titles>
                            <asp:Title Name="Title1" Text="平均天數">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <br />
        <br />
        <br />
        <asp:SqlDataSource ID="keyBuyersSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT userName, COUNT(*) AS tripCount, SUM(total) AS totalSum, AVG(days) AS daysAvg FROM trip GROUP BY userName ORDER BY totalSum DESC, tripCount DESC, daysAvg DESC"></asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
