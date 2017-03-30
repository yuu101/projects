<%@ Page Language="C#" AutoEventWireup="true" CodeFile="myMovie.aspx.cs" Inherits="_03_ASP_07_myMovie_myMovie" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Simple Order</title>
    <link href="../../Styles/3_tripStyleSheet.css" rel="stylesheet" />
   
    <style type="text/css">
        #player {
            width: 518px;
            height: 391px;
        }
        .auto-style2 {
            height: 42px;
            text-align: left;
            width: 374px;
        }
        .auto-style3 {
            height: 42px;
            width: 516px;
        }
        .auto-style4 {
            width: 516px;
        }
        .auto-style5 {
            width: 374px;
        }
        .body {
            height: 1114px;
        }
        .auto-style6 {
            width: 100%;
        }
    </style>
   
</head>
<body class="body">
    <form id="form1" runat="server">
    <div style="height: 1192px; width: 1014px">
    
        <span class="title">&nbsp;我要看電影</span><br />
        <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />

        <br />
        <br />
        <asp:ImageButton ID="ImageButton1" runat="server" Height="242px" ImageUrl="http://www.ambassador.com.tw/assets/img/movies/DivergentSeriesInsurgent01_640x960.jpg" OnClick="ImageButton1_Click" Width="179px" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:ImageButton ID="ImageButton2" runat="server" Height="243px" ImageUrl="http://www.ambassador.com.tw/assets/img/movies/AvengersAgeofUltron01_640x960.jpg" OnClick="ImageButton2_Click" Width="166px" />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:ImageButton ID="ImageButton3" runat="server" ImageUrl="http://www.ambassador.com.tw/assets/img/movies/FastFurious701_640x960.jpg" OnClick="ImageButton3_Click" Width="161px" />
        <br />
        <br />
    
         &nbsp;<table>
            <tr>
                <td class="auto-style3">
                    <asp:Label ID="titleLabel" runat="server" CssClass="subTitle" style="text-align: left" Text="Label"></asp:Label>
                    <br />
                </td>
                <td class="auto-style2">
                    <asp:Label ID="engLabel" runat="server" Text="Label" CssClass="subTitle"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="auto-style4"><div id="player">
        </div>
                </td>
                <td class="auto-style5">
                    <asp:Label ID="contentLabel" runat="server" CssClass="tableContent" Text="Label"></asp:Label>
                    <br />
                    <br />
                    <br />
                    <br />
                    <br />
                    片長：<asp:Label ID="timeLabel" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
        </table>
        &nbsp;
        <br />

        <asp:HiddenField ID="youtubeIdHiddenField" runat="server" />

        <br />
        <span class="subTitle">立即訂票!!</span><br />
        <br />
        <table class="auto-style6">
            <tr>
                <td class="tableHead">名稱：</td>
                <td>
                    <asp:Label ID="subtitleLabel" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="tableHead">票價：</td>
                <td>
                    <asp:Label ID="priceLabel" runat="server" Text="Label" CssClass="tableContent"></asp:Label>
                </td>
            </tr>
            <tr>
                <td class="tableHead">張數：</td>
                <td>
                    <asp:TextBox ID="ticketsTextBox" runat="server" CssClass="tableContent" Height="19px" OnTextChanged="ticketsTextBox_OnTextChanged" AutoPostBack="True"></asp:TextBox>
                &nbsp;</td>
            </tr>
            <tr>
                <td class="tableHead">總價：</td>
                <td>
                    <asp:Label ID="totalLabel" runat="server" Text="Label" CssClass="tableContent"></asp:Label>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <asp:Button ID="goButton" runat="server" Text="買了" OnClick="goButton_Click" />
        <br />

    </div>
        <br />
        <br />
        <br />
    </form>
</body>
</html>

<script src="../../JavaScript/youtubeOrderJavaScript%20.js"></script>
<script type="text/javascript" src="http://www.youtube.com/iframe_api"></script>