<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ListItemPage.aspx.cs" Inherits="UserAuth1.ListItemPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:CheckBoxList ID="CheckBoxList1" runat="server" OnSelectedIndexChanged="ItemSelected">
    <asp:ListItem Value="10"> $ 10 </asp:ListItem>
    <asp:ListItem Value="20"> $ 20 </asp:ListItem>
    <asp:ListItem Value="30"> $ 20 </asp:ListItem>
    <asp:ListItem Value="40"> $ 40 </asp:ListItem>
    <asp:ListItem Value="50"> $ 50 </asp:ListItem>
    <asp:ListItem Value="60"> $ 60 </asp:ListItem>
            </asp:CheckBoxList>
        </div>
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
    </form>
</body>
</html>
