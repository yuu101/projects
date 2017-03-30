<%@ Page Language="C#" AutoEventWireup="true" CodeFile="simpleMail.aspx.cs" Inherits="_09_YouTravel_mail_simpleMail" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>simpleMail</title>
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
    
        <span class="title">小郵差</span><br />
        <br />
        <table class="auto-style1">
            <tr>
                <td class="tableHead">寄件人</td>
                <td class="tableContent">
                    <asp:TextBox ID="senderNameTextBox" runat="server" OnTextChanged="TextBox1_TextChanged"></asp:TextBox>
                </td>
                <td class="tableContent">email</td>
                <td>
                    <asp:TextBox ID="senderAddressTextBox" runat="server" CssClass="tableContent"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="tableHead">收件人</td>
                <td class="tableContent">
                    <asp:TextBox ID="receiverNameTextBox" runat="server"></asp:TextBox>
                </td>
                <td class="tableContent">email</td>
                <td>
                    <asp:TextBox ID="receiverAddressTextBox" runat="server" CssClass="tableContent"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="tableHead">主旨</td>
                <td colspan="3">
                    <asp:TextBox ID="subjectTextBox" runat="server" Width="100%"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="tableHead">內容</td>
                <td colspan="3">
                    <asp:TextBox ID="messageTextBox" runat="server" Height="60px" TextMode="MultiLine" Width="100%"></asp:TextBox>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <asp:Button ID="sendButton" runat="server" OnClick="sendButton_Click" Text="寄信" />
    
    </div>
    </form>
</body>
</html>
