<%@ Page Language="C#" AutoEventWireup="true" CodeFile="ajaxVote.aspx.cs" Inherits="_06_AJAX_vote_ajaxVote" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Vote</title>
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
    
        <span class="title">&nbsp;VOTE</span><br />
        <table class="auto-style1">
            <tr>
                <td>
                    <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource1" DataTextField="season" DataValueField="seasonId" OnSelectedIndexChanged="RadioButtonList1_SelectedIndexChanged" RepeatDirection="Horizontal">
                    </asp:RadioButtonList>
                    <asp:FormView ID="FormView1" runat="server" DataKeyNames="seasonId" DataSourceID="SqlDataSource1">
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
                            <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                        </ItemTemplate>
                    </asp:FormView>
                    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="最水" />
                    <br />
                    <asp:DataList ID="DataList1" runat="server" CellPadding="4" DataKeyField="seasonId" DataSourceID="SqlDataSource3" ForeColor="#333333" RepeatDirection="Horizontal">
                        <AlternatingItemStyle BackColor="White" />
                        <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                        <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                        <ItemStyle BackColor="#EFF3FB" />
                        <ItemTemplate>
                            &nbsp;<asp:Label ID="seasonLabel" runat="server" Text='<%# Eval("season") %>' />
                            <br />
                            得票:
                            <asp:Label ID="Expr1Label" runat="server" Text='<%# Eval("Expr1") %>' />
                            <br />
                            <br />
<br />
                        </ItemTemplate>
                        <SelectedItemStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
                    </asp:DataList>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [season]"></asp:SqlDataSource>
                    <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [poll] WHERE [pollId] = @pollId" InsertCommand="INSERT INTO [poll] ([seasonId], [pollTime]) VALUES (@seasonId, @pollTime)" SelectCommand="SELECT * FROM [poll]" UpdateCommand="UPDATE [poll] SET [seasonId] = @seasonId, [pollTime] = @pollTime WHERE [pollId] = @pollId">
                        <DeleteParameters>
                            <asp:Parameter Name="pollId" Type="Int32" />
                        </DeleteParameters>
                        <InsertParameters>
                            <asp:ControlParameter ControlID="RadioButtonList1" Name="seasonId" PropertyName="SelectedValue" Type="Int32" />
                            <asp:Parameter Name="pollTime" Type="DateTime" />
                        </InsertParameters>
                        <UpdateParameters>
                            <asp:Parameter Name="seasonId" Type="Int32" />
                            <asp:Parameter Name="pollTime" Type="DateTime" />
                            <asp:Parameter Name="pollId" Type="Int32" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                    <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT season.season, COUNT(poll.pollId) AS Expr1, season.seasonId FROM poll INNER JOIN season ON poll.seasonId = season.seasonId GROUP BY season.season, season.seasonId ORDER BY season.seasonId"></asp:SqlDataSource>
                </td>
                <td>
                    <asp:RadioButtonList ID="RadioButtonList2" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource4" DataTextField="title" DataValueField="beerId" RepeatDirection="Horizontal" OnSelectedIndexChanged="RadioButtonList2_SelectedIndexChanged">
                    </asp:RadioButtonList>
                    <asp:FormView ID="FormView2" runat="server" DataKeyNames="beerId" DataSourceID="SqlDataSource4" OnDataBound="FormView2_DataBound">
                        <EditItemTemplate>
                            beerId:
                            <asp:Label ID="beerIdLabel1" runat="server" Text='<%# Eval("beerId") %>' />
                            <br />
                            title:
                            <asp:TextBox ID="titleTextBox" runat="server" Text='<%# Bind("title") %>' />
                            <br />
                            youtubeId:
                            <asp:TextBox ID="youtubeIdTextBox" runat="server" Text='<%# Bind("youtubeId") %>' />
                            <br />
                            <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                            &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                        </EditItemTemplate>
                        <InsertItemTemplate>
                            title:
                            <asp:TextBox ID="titleTextBox" runat="server" Text='<%# Bind("title") %>' />
                            <br />
                            youtubeId:
                            <asp:TextBox ID="youtubeIdTextBox" runat="server" Text='<%# Bind("youtubeId") %>' />
                            <br />
                            <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                            &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
                        </InsertItemTemplate>
                        <ItemTemplate>
                            <asp:HiddenField ID="HiddenField2" runat="server" OnValueChanged="youtubeIdHiddenField_ValueChanged" Value='<%# Eval("youtubeId") %>' />
                            <br />

                            <div id="player">
                            </div>
                        </ItemTemplate>
                    </asp:FormView>
                    <br />
                    <asp:Button ID="Button2" runat="server" Text="想喝" OnClick="Button2_Click" />
                    <br />
                    <asp:DataList ID="DataList2" runat="server" CellPadding="4" DataSourceID="SqlDataSource6" ForeColor="#333333" RepeatDirection="Horizontal">
                        <AlternatingItemStyle BackColor="White" />
                        <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                        <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
                        <ItemStyle BackColor="#EFF3FB" />
                        <ItemTemplate>
                            <asp:Label ID="titleLabel" runat="server" Text='<%# Eval("title") %>' />
                            <br />
                            得票:
                            <asp:Label ID="Expr1Label" runat="server" Text='<%# Eval("Expr1") %>' />
                            <br />
                            <br />
                        </ItemTemplate>
                        <SelectedItemStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
                    </asp:DataList>
                    <asp:SqlDataSource ID="SqlDataSource4" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT * FROM [beer]"></asp:SqlDataSource>
                    <asp:SqlDataSource ID="SqlDataSource5" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" DeleteCommand="DELETE FROM [beerPoll] WHERE [beerPollId] = @beerPollId" InsertCommand="INSERT INTO [beerPoll] ([beerId]) VALUES (@beerId)" SelectCommand="SELECT * FROM [beerPoll]" UpdateCommand="UPDATE [beerPoll] SET [beerId] = @beerId WHERE [beerPollId] = @beerPollId">
                        <DeleteParameters>
                            <asp:Parameter Name="beerPollId" Type="Int32" />
                        </DeleteParameters>
                        <InsertParameters>
                            <asp:ControlParameter ControlID="RadioButtonList2" Name="beerId" PropertyName="SelectedValue" Type="Int32" />
                        </InsertParameters>
                        <UpdateParameters>
                            <asp:Parameter Name="beerId" Type="Int32" />
                            <asp:Parameter Name="beerPollId" Type="Int32" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                    <asp:SqlDataSource ID="SqlDataSource6" runat="server" ConnectionString="<%$ ConnectionStrings:WWW71ConnectionString %>" SelectCommand="SELECT beerPoll.beerId, beer.title, COUNT(beerPoll.beerPollId) AS Expr1 FROM beer INNER JOIN beerPoll ON beer.beerId = beerPoll.beerId GROUP BY beerPoll.beerId, beer.title"></asp:SqlDataSource>
                    <asp:HiddenField ID="youtubeHiddenField" runat="server" />
                    <br />
                </td>
            </tr>
        </table>
    
    </div>
    </form>
</body>
</html>
<script src="../../JavaScript/youtubeIdjavaScript.js"></script>
<script type="text/javascript" src="https://www.youtube.com/iframe_api"></script>