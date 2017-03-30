<%@ Page Language="C#" AutoEventWireup="true" CodeFile="21_seasonPoll1.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_21_seasonPoll1" %>

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
    
        <div>
            <span class="title">你認為哪個季節最美</span><br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td>選項：</td>
                    <td>
                        <asp:RadioButtonList ID="seasonRadioButtonList" runat="server" AutoPostBack="True" DataSourceID="seasonSqlDataSource" DataTextField="season" DataValueField="seasonId" Height="23px" Width="113px">
                        </asp:RadioButtonList>
                    </td>
                </tr>
            </table>
            <br />
            <asp:Button ID="goButton" runat="server" Text="投他一票!" OnClick="goButton_Click" />
            <br />
            <br />
            <asp:SqlDataSource ID="seasonSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [season]"></asp:SqlDataSource>
            <asp:SqlDataSource ID="pollSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [poll] WHERE [pollId] = @pollId" InsertCommand="INSERT INTO [poll] ([seasonId], [pollTime]) VALUES (@seasonId, @pollTime)" SelectCommand="SELECT * FROM [poll]" UpdateCommand="UPDATE [poll] SET [seasonId] = @seasonId, [pollTime] = @pollTime WHERE [pollId] = @pollId">
                <DeleteParameters>
                    <asp:Parameter Name="pollId" Type="Int32" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:SessionParameter Name="seasonId" SessionField="seasonId" Type="Int32" />
                    <asp:Parameter Name="pollTime" Type="DateTime" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="seasonId" Type="Int32" />
                    <asp:Parameter Name="pollTime" Type="DateTime" />
                    <asp:Parameter Name="pollId" Type="Int32" />
                </UpdateParameters>
            </asp:SqlDataSource>
            <br />
        </div>
    
    </div>
    </form>
</body>
</html>
