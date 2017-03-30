<%@ Page Language="C#" AutoEventWireup="true" CodeFile="21_movieGrade1.aspx.cs" Inherits="_05_Midterm_052_Test_II__0412_21_movieGrade1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>vote1</title>
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
            <span class="title">你認為哪部影片最棒</span><br />
            <br />
            <asp:RadioButtonList ID="movieRadioButtonList" runat="server" AutoPostBack="True" CssClass="subTitle" DataSourceID="movieSqlDataSource" DataTextField="movie" DataValueField="movieId">
            </asp:RadioButtonList>
            <br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td><span class="subTitle">評分：</span></td>
                    <td>
                        <asp:DropDownList ID="gradeDropDownList" runat="server" AutoPostBack="True">
                            <asp:ListItem Value="1">★</asp:ListItem>
                            <asp:ListItem Value="2">★★</asp:ListItem>
                            <asp:ListItem Value="3">★★★</asp:ListItem>
                            <asp:ListItem Value="4">★★★★</asp:ListItem>
                            <asp:ListItem Value="5">★★★★★</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                </tr>
            </table>
            <br />
            <asp:Button ID="goButton" runat="server" OnClick="goButton_Click" Text="投票" />
            <br />
            <br />
            <asp:SqlDataSource ID="movieSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [movie]"></asp:SqlDataSource>
            <br />
            <asp:SqlDataSource ID="gradeSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [movieGrade] WHERE [gradeId] = @gradeId" InsertCommand="INSERT INTO [movieGrade] ([movieId], [grade], [gradeTime]) VALUES (@movieId, @grade, @gradeTime)" SelectCommand="SELECT * FROM [movieGrade]" UpdateCommand="UPDATE [movieGrade] SET [movieId] = @movieId, [grade] = @grade, [gradeTime] = @gradeTime WHERE [gradeId] = @gradeId">
                <DeleteParameters>
                    <asp:Parameter Name="gradeId" Type="Int32" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:SessionParameter Name="movieId" SessionField="movieId" Type="Int32" />
                    <asp:SessionParameter Name="grade" SessionField="grade" Type="Int32" />
                    <asp:Parameter Name="gradeTime" Type="DateTime" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="movieId" Type="Int32" />
                    <asp:Parameter Name="grade" Type="Int32" />
                    <asp:Parameter Name="gradeTime" Type="DateTime" />
                    <asp:Parameter Name="gradeId" Type="Int32" />
                </UpdateParameters>
            </asp:SqlDataSource>
            <br />
        </div>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
        <p>
            &nbsp;</p>
    </form>
</body>
</html>
