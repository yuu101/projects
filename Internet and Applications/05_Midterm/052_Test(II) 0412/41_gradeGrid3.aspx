<%@ Page Language="C#" AutoEventWireup="true" CodeFile="41_gradeGrid3.aspx.cs" Inherits="_05_Midterm_052_Test_II__0412_41_gradeGrid3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>result1</title>
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
    
        <span class="title">最佳影片 得分及評分統計表</span><br />
        <br />
        <asp:DataList ID="DataList1" runat="server" DataKeyField="movieId" DataSourceID="SqlDataSource1" OnItemCommand="DataList1_ItemCommand" RepeatDirection="Horizontal">
            <ItemTemplate>
                <asp:Label ID="movieLabel" runat="server" Text='<%# Eval("movie") %>' />
                <br />
                <br />
                <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
            </ItemTemplate>
        </asp:DataList>
        <br />
        <br />
        <br />
        <br />
        <asp:FormView ID="FormView1" runat="server" DataSourceID="SqlDataSource2">
            <EditItemTemplate>
                movieId:
                <asp:TextBox ID="movieIdTextBox" runat="server" Text='<%# Bind("movieId") %>' />
                <br />
                Expr1:
                <asp:TextBox ID="Expr1TextBox" runat="server" Text='<%# Bind("Expr1") %>' />
                <br />
                movie:
                <asp:TextBox ID="movieTextBox" runat="server" Text='<%# Bind("movie") %>' />
                <br />
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </EditItemTemplate>
            <InsertItemTemplate>
                movieId:
                <asp:TextBox ID="movieIdTextBox" runat="server" Text='<%# Bind("movieId") %>' />
                <br />
                Expr1:
                <asp:TextBox ID="Expr1TextBox" runat="server" Text='<%# Bind("Expr1") %>' />
                <br />
                movie:
                <asp:TextBox ID="movieTextBox" runat="server" Text='<%# Bind("movie") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </InsertItemTemplate>
            <ItemTemplate>
                <br />
                <table class="auto-style1">
                    <tr>
                        <td>電影：</td>
                        <td>
                            <asp:Label ID="movieLabel" runat="server" Text='<%# Bind("movie") %>' />
                        </td>
                        <td>&nbsp;</td>
                        <td>得分：</td>
                        <td>
                            <asp:Label ID="Expr1Label" runat="server" Text='<%# Bind("Expr1") %>' />
                        </td>
                    </tr>
                </table>
                <br />
                <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="gradeId" DataSourceID="SqlDataSource3" ForeColor="#333333" GridLines="None">
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
            </ItemTemplate>
        </asp:FormView>
        <br />
        <br />
        <br />
        <br />
        <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT movieGrade.gradeId, movieGrade.movieId, movieGrade.grade, movieGrade.gradeTime, movie.movie FROM movie INNER JOIN movieGrade ON movie.movieId = movieGrade.movieId WHERE (movieGrade.movieId = @index )">
            <SelectParameters>
                <asp:SessionParameter DefaultValue="" Name="index" SessionField="index" />
            </SelectParameters>
        </asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT movieGrade.movieId, SUM(movieGrade.grade) AS Expr1, movie.movie FROM movieGrade INNER JOIN movie ON movieGrade.movieId = movie.movieId GROUP BY movieGrade.movieId, movie.movie

"></asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [movie]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
