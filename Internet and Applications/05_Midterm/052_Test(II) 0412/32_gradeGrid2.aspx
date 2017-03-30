<%@ Page Language="C#" AutoEventWireup="true" CodeFile="32_gradeGrid2.aspx.cs" Inherits="_05_Midterm_052_Test_II__0412_32_gradeGrid2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>view2</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">最佳影片 評分列表</span><br />
        <br />
        <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="gradeId" DataSourceID="gradeSqlDataSource" ForeColor="#333333" GridLines="None">
            <AlternatingRowStyle BackColor="White" />
            <Columns>
                <asp:BoundField DataField="gradeId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="gradeId" />
                <asp:BoundField DataField="movie" HeaderText="電影" SortExpression="movie" />
                <asp:BoundField DataField="grade" HeaderText="評分" SortExpression="grade" />
                <asp:BoundField DataField="gradeTime" HeaderText="評分時間" SortExpression="gradeTime" />
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
        <asp:SqlDataSource ID="gradeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT movieGrade.gradeId, movieGrade.movieId, movieGrade.grade, movie.movie, movieGrade.gradeTime FROM movieGrade INNER JOIN movie ON movieGrade.movieId = movie.movieId ORDER BY movieGrade.gradeId DESC"></asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
