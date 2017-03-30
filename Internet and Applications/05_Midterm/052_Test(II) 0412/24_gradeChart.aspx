<%@ Page Language="C#" AutoEventWireup="true" CodeFile="24_gradeChart.aspx.cs" Inherits="_05_Midterm_052_Test_II__0412_24_gradeChart" %>

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
            <span class="title">最佳影片 評分統計圖</span><br />
            <br />
            <asp:Chart ID="Chart1" runat="server" DataSourceID="gradeSqlDataSource" EnableTheming="False">
                <Series>
                    <asp:Series Name="Series1" XValueMember="movie" YValueMembers="Expr1" ChartType="Doughnut" IsValueShownAsLabel="True" IsXValueIndexed="True" Legend="備註">
                    </asp:Series>
                </Series>
                <ChartAreas>
                    <asp:ChartArea Name="ChartArea1">
                    </asp:ChartArea>
                </ChartAreas>
                <Legends>
                    <asp:Legend Name="備註">
                    </asp:Legend>
                </Legends>
            </asp:Chart>
            <br />
            <asp:SqlDataSource ID="gradeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT movieGrade.movieId, SUM(movieGrade.grade) AS Expr1, movie.movie FROM movieGrade INNER JOIN movie ON movieGrade.movieId = movie.movieId GROUP BY movieGrade.movieId, movie.movie"></asp:SqlDataSource>
        </div>
        <p>
            &nbsp;</p>
    </form>
</body>
</html>
