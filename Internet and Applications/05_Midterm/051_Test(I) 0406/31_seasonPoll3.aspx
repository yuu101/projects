<%@ Page Language="C#" AutoEventWireup="true" CodeFile="31_seasonPoll3.aspx.cs" Inherits="_05_Midterm_051_Test_I__0406_31_seasonPoll3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>vote3</title>
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
            <br />
            <table class="auto-style1">
                <tr>
                    <td>選項：</td>
                    <td>
                        <asp:RadioButtonList ID="seasonRadioButtonList" runat="server" AutoPostBack="True" DataSourceID="seasonSqlDataSource" DataTextField="season" DataValueField="seasonId" OnSelectedIndexChanged="seasonRadioButtonList_SelectedIndexChanged">
                        </asp:RadioButtonList>
                    </td>
                </tr>
            </table>
            <br />
            <asp:FormView ID="seasonFormView" runat="server" DataKeyNames="seasonId" DataSourceID="seasonSqlDataSource">
                <EditItemTemplate>
                    seasonId:
                    <asp:Label ID="seasonIdLabel1" runat="server" Text='<%# Eval("seasonId") %>' />
                    <br />
                    season:
                    <asp:TextBox ID="seasonTextBox" runat="server" Text='<%# Bind("season") %>' />
                    <br />
                    flickrId:
                    <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                    <br />
                    <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                    &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                </EditItemTemplate>
                <InsertItemTemplate>
                    season:
                    <asp:TextBox ID="seasonTextBox" runat="server" Text='<%# Bind("season") %>' />
                    <br />
                    flickrId:
                    <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                    <br />
                    <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                    &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                </InsertItemTemplate>
                <ItemTemplate>
                    <br />

                    <asp:Image ID="seasonImage" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                </ItemTemplate>
            </asp:FormView>
            <asp:Button ID="goButton" runat="server" OnClick="goButton_Click" Text="投他一票!" />
            <br />
            <br />
            <br />
            <asp:Label ID="timeLabel" runat="server" Text="Label"></asp:Label>
            <br />
            <br />
            <br />
            <asp:SqlDataSource ID="seasonSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [season]"></asp:SqlDataSource>
            <br />
            <asp:SqlDataSource ID="pollSqlDataSource" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [poll] WHERE [pollId] = @pollId" InsertCommand="INSERT INTO [poll] ([seasonId], [pollTime]) VALUES (@seasonId, @pollTime)" SelectCommand="SELECT * FROM [poll]" UpdateCommand="UPDATE [poll] SET [seasonId] = @seasonId, [pollTime] = @pollTime WHERE [pollId] = @pollId">
                <DeleteParameters>
                    <asp:Parameter Name="pollId" Type="Int32" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:SessionParameter Name="seasonId" SessionField="seasonId" Type="Int32" />
                    <asp:SessionParameter Name="pollTime" SessionField="pollTime" Type="DateTime" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="seasonId" Type="Int32" />
                    <asp:Parameter Name="pollTime" Type="DateTime" />
                    <asp:Parameter Name="pollId" Type="Int32" />
                </UpdateParameters>
            </asp:SqlDataSource>
        </div>
    
    </div>
    </form>
</body>
</html>
