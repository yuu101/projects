<%@ Page Language="C#" AutoEventWireup="true" CodeFile="youtubeTrip.aspx.cs" Inherits="_03_ASP_02_youtube_youtubeTrip" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Youtube Trip</title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
</head>

<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">我要去旅行</span><br />
        <br />
        <table>
            <tr>
                <td><span class="tableHead">旅行者：</span> </td>
                <td>
                    <asp:TextBox ID="userTextBox" runat="server" CssClass="tableContent"></asp:TextBox>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="userTextBox" Display="Dynamic" ErrorMessage="請輸入姓名!" ForeColor="#FF0066"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td><span class="tableHead">旅行地：</span> </td>
                <td>
                    <asp:RadioButtonList ID="placeRadioButtonList" runat="server" RepeatDirection="Horizontal" CssClass="formViewContent">
                        <asp:ListItem Selected="True" Value="1i1bZvbN0FQ">東京</asp:ListItem>
                        <asp:ListItem Value="WHVPk1oS4ME">紐約</asp:ListItem>
                        <asp:ListItem Value="TZM3bMkHrI0">倫敦</asp:ListItem>
                    </asp:RadioButtonList>
                </td>
            </tr>
        </table>
        <br />
        <asp:Button ID="goButton" runat="server" Text="走吧" OnClick="goButton_Click" />
        <br />
    
    </div>
    </form>
    </body>
</html>
