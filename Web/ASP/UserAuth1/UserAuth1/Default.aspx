<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="UserAuth1.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Home Page</title>
</head>
<body>
    <h3>This is the Home Page</h3>
    <form id="form1" runat="server">
        <div>
            <asp:LoginView ID="LoginView1" runat="server"></asp:LoginView>
        </div>
    </form>
</body>
</html>
