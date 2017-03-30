<%@ Page Language="C#" AutoEventWireup="true" CodeFile="24_pollChart.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_24_pollChart" %>

<%@ Register assembly="System.Web.DataVisualization, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35" namespace="System.Web.UI.DataVisualization.Charting" tagprefix="asp" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>chart</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">最美的季節 票數統計圖<br />
        </span>
        <br />
        <br />
        <asp:Chart ID="Chart1" runat="server" DataSourceID="pollSqlDataSource">
            <series>
                <asp:Series Name="Series1" XValueMember="season" YValueMembers="Expr1">
                </asp:Series>
            </series>
            <chartareas>
                <asp:ChartArea Name="ChartArea1">
                </asp:ChartArea>
            </chartareas>
        </asp:Chart>
        <br />
        <br />
        <asp:SqlDataSource ID="pollSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT COUNT(poll.seasonId) AS Expr1, poll.seasonId, season.season FROM poll INNER JOIN season ON poll.seasonId = season.seasonId GROUP BY poll.seasonId, season.season"></asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
