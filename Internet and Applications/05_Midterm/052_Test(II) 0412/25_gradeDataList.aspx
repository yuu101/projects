<%@ Page Language="C#" AutoEventWireup="true" CodeFile="25_gradeDataList.aspx.cs" Inherits="_05_Midterm_052_Test_II__0412_25_gradeDataList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>list</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="body">
    <div>
    
        <span class="title">最佳影片&nbsp; 得分統計</span><br />
        <br />
        <asp:DataList ID="DataList1" runat="server" CellPadding="4" DataSourceID="SqlDataSource1" ForeColor="#333333" RepeatDirection="Horizontal">
            <AlternatingItemStyle BackColor="White" />
            <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
            <ItemStyle BackColor="#EFF3FB" />
            <ItemTemplate>
                <asp:Label ID="movieLabel" runat="server" Text='<%# Eval("movie") %>' />
                <br />
                <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                <br />
                <table class="auto-style1">
                    <tr>
                        <td>得分：</td>
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
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT movieGrade.movieId, SUM(movieGrade.grade) AS Expr1, movie.movie, movie.flickrId FROM movieGrade INNER JOIN movie ON movieGrade.movieId = movie.movieId GROUP BY movieGrade.movieId, movie.movie, movie.flickrId"></asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
