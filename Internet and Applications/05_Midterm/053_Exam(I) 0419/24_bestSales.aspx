<%@ Page Language="C#" AutoEventWireup="true" CodeFile="24_bestSales.aspx.cs" Inherits="_05_Midterm_053_Exam_I__0419_24_bestSales
" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Datalist    </title>
    <link href="../../Styles/tripStyleSheet.css" rel="stylesheet" />
    </head>
<body class="body">
    <form id="form1" runat="server">
    <div>
    
        <span class="title">銷售第一</span><br />
        <br />
        <br />
        <asp:RadioButtonList ID="RadioButtonList1" runat="server" AutoPostBack="True" DataSourceID="SqlDataSource1" DataTextField="category" DataValueField="categoryId" RepeatDirection="Horizontal">
        </asp:RadioButtonList>
        <asp:FormView ID="FormView1" runat="server" DataSourceID="SqlDataSource2" HorizontalAlign="Center">
            <EditItemTemplate>
                Expr1:
                <asp:TextBox ID="Expr1TextBox" runat="server" Text='<%# Bind("Expr1") %>' />
                <br />
                Expr2:
                <asp:TextBox ID="Expr2TextBox" runat="server" Text='<%# Bind("Expr2") %>' />
                <br />
                categoryId:
                <asp:TextBox ID="categoryIdTextBox" runat="server" Text='<%# Bind("categoryId") %>' />
                <br />
                productName:
                <asp:TextBox ID="productNameTextBox" runat="server" Text='<%# Bind("productName") %>' />
                <br />
                flickrId:
                <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                <br />
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="更新" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </EditItemTemplate>
            <InsertItemTemplate>
                Expr1:
                <asp:TextBox ID="Expr1TextBox" runat="server" Text='<%# Bind("Expr1") %>' />
                <br />
                Expr2:
                <asp:TextBox ID="Expr2TextBox" runat="server" Text='<%# Bind("Expr2") %>' />
                <br />
                categoryId:
                <asp:TextBox ID="categoryIdTextBox" runat="server" Text='<%# Bind("categoryId") %>' />
                <br />
                productName:
                <asp:TextBox ID="productNameTextBox" runat="server" Text='<%# Bind("productName") %>' />
                <br />
                flickrId:
                <asp:TextBox ID="flickrIdTextBox" runat="server" Text='<%# Bind("flickrId") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="插入" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="取消" />
            </InsertItemTemplate>
            <ItemTemplate>
                <asp:Label ID="productNameLabel" runat="server" Text='<%# Bind("productName") %>' />
                <br />
                <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("flickrId", "http://farm9.staticflickr.com/{0}") %>' />
                <br />
                總額： 
                <asp:Label ID="Expr1Label" runat="server" Text='<%# Bind("Expr1") %>' />
                <br />
                總量：<asp:Label ID="Expr2Label" runat="server" Text='<%# Bind("Expr2") %>' />
                <br />
                <br />
                <asp:GridView ID="GridView1" runat="server" AllowSorting="True" AutoGenerateColumns="False" CellPadding="4" DataKeyNames="productId" DataSourceID="SqlDataSource2" ForeColor="#333333" GridLines="None">
                    <AlternatingRowStyle BackColor="White" />
                    <Columns>
                        <asp:BoundField DataField="productId" HeaderText="序號" InsertVisible="False" ReadOnly="True" SortExpression="productId" />
                        <asp:BoundField DataField="productName" HeaderText="名稱" SortExpression="productName" />
                        <asp:BoundField DataField="Expr2" HeaderText="總量" ReadOnly="True" SortExpression="Expr2" />
                        <asp:BoundField DataField="Expr1" HeaderText="總額" ReadOnly="True" SortExpression="Expr1" />
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
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:examConnectionString %>" SelectCommand="SELECT categoryId, category FROM product GROUP BY categoryId, category"></asp:SqlDataSource>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:examConnectionString %>" SelectCommand="SELECT SUM(sales.total) AS Expr1, COUNT(sales.amount) AS Expr2, product.categoryId, product.productName, product.flickrId, product.productId FROM product INNER JOIN sales ON product.productId = sales.productId GROUP BY product.categoryId, product.productName, product.flickrId, product.productId HAVING (product.categoryId = @categoryId) ORDER BY Expr1 DESC">
            <SelectParameters>
                <asp:ControlParameter ControlID="RadioButtonList1" DefaultValue="1" Name="categoryId" PropertyName="SelectedValue" />
            </SelectParameters>
        </asp:SqlDataSource>
        <br />
    
    </div>
    </form>
</body>
</html>
