<%@ Page Language="C#" AutoEventWireup="true" CodeFile="11_simpleBuy.aspx.cs" Inherits="_05_Midterm_053_Exam_I__0419_11_simpleBuy" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>buy</title>
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
    
        <span class="title">熱門商品採購<br />
        </span>
        <br />
        <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource1" DataTextField="productName" DataValueField="productId" Height="33px" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged" Width="117px">
</asp:DropDownList>
        <br />
&nbsp;<asp:FormView ID="FormView1" runat="server" DataKeyNames="productId" DataSourceID="SqlDataSource1" OnDataBound="FormView1_DataBound">
            <EditItemTemplate>
                productId:
                <asp:Label ID="productIdLabel1" runat="server" Text='<%# Eval("productId") %>' />
                <br />
                productName:
                <asp:TextBox ID="productNameTextBox" runat="server" Text='<%# Bind("productName") %>' />
                <br />
                categoryId:
                <asp:TextBox ID="categoryIdTextBox" runat="server" Text='<%# Bind("categoryId") %>' />
                <br />
                category:
                <asp:TextBox ID="categoryTextBox" runat="server" Text='<%# Bind("category") %>' />
                <br />
                price:
                <asp:TextBox ID="priceTextBox" runat="server" Text='<%# Bind("price") %>' />
                <br />
                flickrId:
                <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                <br />
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </EditItemTemplate>
            <InsertItemTemplate>
                productName:
                <asp:TextBox ID="productNameTextBox" runat="server" Text='<%# Bind("productName") %>' />
                <br />
                categoryId:
                <asp:TextBox ID="categoryIdTextBox" runat="server" Text='<%# Bind("categoryId") %>' />
                <br />
                category:
                <asp:TextBox ID="categoryTextBox" runat="server" Text='<%# Bind("category") %>' />
                <br />
                price:
                <asp:TextBox ID="priceTextBox" runat="server" Text='<%# Bind("price") %>' />
                <br />
                flickrId:
                <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </InsertItemTemplate>
            <ItemTemplate>
                <table class="auto-style1">
                    <tr>
                        <td>單價：</td>
                        <td>
                            <asp:Label ID="priceLabel" runat="server" Text='<%# Bind("price") %>' />
                        </td>
                    </tr>
                </table>
                <br />
            </ItemTemplate>
        </asp:FormView>
        <table class="auto-style1">
    <tr>
        <td class="tableContent">數量：</td>
        <td class="tableContent">
            <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="True" Height="57px" RepeatDirection="Horizontal" Width="74px" OnSelectedIndexChanged="RadioButtonList1_SelectedIndexChanged">
                <asp:ListItem Selected="True" Value="5">5</asp:ListItem>
                <asp:ListItem Value="3">3</asp:ListItem>
                <asp:ListItem Value="1">1</asp:ListItem>
            </asp:RadioButtonList>
        </td>
    </tr>
    <tr>
        <td class="tableContent">總價：</td>
        <td class="tableContent">
            <asp:Label ID="totalLabel" runat="server" Text="Label"></asp:Label>
        </td>
    </tr>
</table>
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Button" />
        <br />
        <br />
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=db.csie.ntut.edu.tw,2819;Initial Catalog=exam;Persist Security Info=True;User ID=student;Password=s1234" ProviderName="System.Data.SqlClient" SelectCommand="SELECT * FROM [product]"></asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:examConnectionString %>" DeleteCommand="DELETE FROM [sales] WHERE [salesId] = @salesId" InsertCommand="INSERT INTO [sales] ([productId], [amount], [total]) VALUES (@productId, @amount, @total)" SelectCommand="SELECT * FROM [sales]" UpdateCommand="UPDATE [sales] SET [productId] = @productId, [amount] = @amount, [total] = @total WHERE [salesId] = @salesId">
            <DeleteParameters>
                <asp:Parameter Name="salesId" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:ControlParameter ControlID="FormView1" Name="productId" PropertyName="SelectedValue" Type="Int32" />
                <asp:ControlParameter ControlID="RadioButtonList1" Name="amount" PropertyName="SelectedValue" Type="Int32" />
                <asp:SessionParameter Name="total" SessionField="total" Type="Int32" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="productId" Type="Int32" />
                <asp:Parameter Name="amount" Type="Int32" />
                <asp:Parameter Name="total" Type="Int32" />
                <asp:Parameter Name="salesId" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
