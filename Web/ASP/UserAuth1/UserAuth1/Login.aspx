<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="UserAuth1.Login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Login Page</title>
</head>
<body>
    <h2>Welcome to Awesome Login Page</h2>

    <asp:Login ID="Login1" runat="server"></asp:Login>
    <asp:ValidationSummary ID="ValidationSummary1" runat="server" ValidationGroup="Login1" />
    <form id="form1" runat="server">
        <div>
        </div>
    </form>
</body>
</html>
