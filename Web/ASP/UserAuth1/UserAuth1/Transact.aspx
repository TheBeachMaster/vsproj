<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Transact.aspx.cs" Inherits="UserAuth1.Transact" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Goods Page</title>
    <link href="Contents/bootstrap-theme.min.css" rel="stylesheet" />
    <link href="Contents/bootstrap.min.css" rel="stylesheet" />
    <script src="Scripts/bootstrap.js"></script>
    <script src="Scripts/bootstrap.min.js"></script>
    <script src="Scripts/jQuery.js"></script>
    <script src="Scripts/npm.js"></script>
</head>
<body>
    <form id="form1" runat="server">
        <div class="container">
            <asp:CheckBoxList ID="ItemsList" runat="server">

            </asp:CheckBoxList>
        </div>
    </form>
</body>
</html>
