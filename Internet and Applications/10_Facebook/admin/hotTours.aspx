<%@ Page Language="C#" AutoEventWireup="true" CodeFile="hotTours.aspx.cs" Inherits="_10_Facebook_admin_hotTours" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>hotTours</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            height: 20px;
        }
    </style>
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">熱門商品排行榜</span><br />
        <br />
        <asp:FormView ID="totalFormView" runat="server" DataSourceID="totalSqlDataSource">
            <EditItemTemplate>
                totalSum:
                <asp:TextBox ID="totalSumTextBox" runat="server" Text='<%# Bind("totalSum") %>' />
                <br />
                tripCount:
                <asp:TextBox ID="tripCountTextBox" runat="server" Text='<%# Bind("tripCount") %>' />
                <br />
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </EditItemTemplate>
            <InsertItemTemplate>
                totalSum:
                <asp:TextBox ID="totalSumTextBox" runat="server" Text='<%# Bind("totalSum") %>' />
                <br />
                tripCount:
                <asp:TextBox ID="tripCountTextBox" runat="server" Text='<%# Bind("tripCount") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </InsertItemTemplate>
            <ItemTemplate>
                營業總額： 
                <asp:Label ID="totalSumLabel" runat="server" Text='<%# Bind("totalSum","{0:N0}") %>' />
                <br />
                旅遊總天數：<asp:Label ID="tripCountLabel" runat="server" Text='<%# Bind("tripCount") %>' />
                <br />

            </ItemTemplate>
        </asp:FormView>
        <br />
        <br />
        <br />
        <table class="auto-style1">
            <tr>
                <td colspan="2">
                    <asp:GridView ID="hotToursGridView" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="tourId" DataSourceID="hotToursSqlDataSource" ForeColor="#333333" GridLines="None">
                        <AlternatingRowStyle BackColor="White" />
                        <Columns>
                            <asp:BoundField DataField="place" HeaderText="地點" SortExpression="place" />
                            <asp:BoundField DataField="placeCount" HeaderText="旅遊人次" ReadOnly="True" SortExpression="placeCount" />
                            <asp:BoundField DataField="totalSum" DataFormatString="{0:N0}" HeaderText="總額" ReadOnly="True" SortExpression="totalSum" />
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
                <td colspan="2">
                    <asp:DataList ID="hotToursDataList" runat="server" DataKeyField="tourId" DataSourceID="hotToursSqlDataSource" OnItemCommand="hotToursDataList_ItemCommand" RepeatDirection="Horizontal">
                        <ItemTemplate>
                            <table class="auto-style1">
                                <tr>
                                    <td>地點：<asp:Label ID="placeLabel" runat="server" Text='<%# Eval("place") %>' />
                                    </td>
                                </tr>
                                <tr>
                                    <td>
                                        <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                                    </td>
                                </tr>
                                <tr>
                                    <td>營業額：<asp:Label ID="totalSumLabel" runat="server" Text='<%# Eval("totalSum","{0:N0}") %>' />
                                    </td>
                                </tr>
                            </table>
<br />
                        </ItemTemplate>
                    </asp:DataList>
                    <asp:FormView ID="placeFormView" runat="server" DataKeyNames="tourId" DataSourceID="hotToursSqlDataSource">
                        <EditItemTemplate>
                            tourId:
                            <asp:Label ID="tourIdLabel1" runat="server" Text='<%# Eval("tourId") %>' />
                            <br />
                            place:
                            <asp:TextBox ID="placeTextBox" runat="server" Text='<%# Bind("place") %>' />
                            <br />
                            placeCount:
                            <asp:TextBox ID="placeCountTextBox" runat="server" Text='<%# Bind("placeCount") %>' />
                            <br />
                            totalSum:
                            <asp:TextBox ID="totalSumTextBox" runat="server" Text='<%# Bind("totalSum") %>' />
                            <br />
                            daysAvg:
                            <asp:TextBox ID="daysAvgTextBox" runat="server" Text='<%# Bind("daysAvg") %>' />
                            <br />
                            price:
                            <asp:TextBox ID="priceTextBox" runat="server" Text='<%# Bind("price") %>' />
                            <br />
                            flickrId:
                            <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                            <br />
                            <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                            &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            place:
                            <asp:TextBox ID="placeTextBox" runat="server" Text='<%# Bind("place") %>' />
                            <br />
                            placeCount:
                            <asp:TextBox ID="placeCountTextBox" runat="server" Text='<%# Bind("placeCount") %>' />
                            <br />
                            totalSum:
                            <asp:TextBox ID="totalSumTextBox" runat="server" Text='<%# Bind("totalSum") %>' />
                            <br />
                            daysAvg:
                            <asp:TextBox ID="daysAvgTextBox" runat="server" Text='<%# Bind("daysAvg") %>' />
                            <br />
                            price:
                            <asp:TextBox ID="priceTextBox" runat="server" Text='<%# Bind("price") %>' />
                            <br />
                            flickrId:
                            <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                            <br />
                            <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                            &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                        </InsertItemTemplate>
                        <ItemTemplate>
                            地點： 
                            <asp:Label ID="placeLabel" runat="server" Text='<%# Bind("place") %>' />
                            <br />
                            單價： 
                            <asp:Label ID="priceLabel" runat="server" Text='<%# Bind("price","{0:N0}") %>' />
                            <br />
                            <br />
                        </ItemTemplate>
                    </asp:FormView>
                </td>
            </tr>
            <tr>
                <td class="auto-style2">
                    <asp:Chart ID="hotToursChart" runat="server" DataSourceID="hotToursSqlDataSource">
                        <Series>
                            <asp:Series Name="Series1" XValueMember="place" YValueMembers="totalSum">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="營業額">
                                </AxisY>
                                <AxisX Title="地點">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Titles>
                            <asp:Title Name="Title1" Text="營業額">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
                <td class="auto-style2">
                    <asp:Chart ID="hotToursMultiChart" runat="server" DataSourceID="hotToursSqlDataSource">
                        <Series>
                            <asp:Series Legend="Legend1" Name="旅行次數" XValueMember="place" YValueMembers="placeCount">
                            </asp:Series>
                            <asp:Series ChartArea="ChartArea1" Legend="Legend1" Name="平均天數" XValueMember="place" YValueMembers="daysAvg">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="次數">
                                </AxisY>
                                <AxisX Title="地點">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Legends>
                            <asp:Legend Name="Legend1">
                            </asp:Legend>
                        </Legends>
                        <Titles>
                            <asp:Title Name="Title1" Text="次數比較">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Chart ID="hotToursRadarChart" runat="server" DataSourceID="hotToursSqlDataSource">
                        <Series>
                            <asp:Series ChartType="Radar" Name="Series1" XValueMember="place" YValueMembers="daysAvg">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="平均天數">
                                </AxisY>
                                <AxisX Title="地點">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Titles>
                            <asp:Title Name="Title1" Text="平均天數">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
                <td>
                    <asp:Chart ID="hotToursPieChart" runat="server" DataSourceID="hotToursSqlDataSource">
                        <Series>
                            <asp:Series ChartType="Pie" IsValueShownAsLabel="True" Name="Series1" XValueMember="place" YValueMembers="placeCount">
                            </asp:Series>
                        </Series>
                        <ChartAreas>
                            <asp:ChartArea Name="ChartArea1">
                                <AxisY Title="旅遊人次">
                                </AxisY>
                                <AxisX Title="地點">
                                </AxisX>
                            </asp:ChartArea>
                        </ChartAreas>
                        <Titles>
                            <asp:Title Name="Title1" Text="旅遊人次">
                            </asp:Title>
                        </Titles>
                    </asp:Chart>
                </td>
            </tr>
        </table>
        <br />
        <asp:SqlDataSource ID="hotToursSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT tour.tourId, tour.place, COUNT(*) AS placeCount, SUM(trip.total) AS totalSum, AVG(trip.days) AS daysAvg, tour.price, tour.flickrId FROM tour INNER JOIN trip ON tour.tourId = trip.tourId GROUP BY tour.tourId, tour.place, tour.price, tour.flickrId ORDER BY totalSum DESC, placeCount DESC, daysAvg DESC"></asp:SqlDataSource>
    
        <asp:SqlDataSource ID="totalSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT SUM(total) AS totalSum, COUNT(tripId) AS tripCount FROM trip"></asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
