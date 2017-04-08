<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ListItemPage.aspx.cs" Inherits="UserAuth1.ListItemPage" %>

<!DOCTYPE html>


<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>

    <link href="Contents/bootstrap-theme.css" rel="stylesheet" />
    <link href="Contents/bootstrap.min.css" rel="stylesheet" />
    <script src="Scripts/bootstrap.js"></script>
    <script src="Scripts/bootstrap.min.js"></script>
    <script src="Scripts/jQuery.js"></script>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:CheckBoxList  ID="CheckBoxList1" runat="server">
                
                <asp:ListItem   Value="10"> $ 10 </asp:ListItem>
                <asp:ListItem Value="20"> $ 20 </asp:ListItem>
                <asp:ListItem Value="30"> $ 30 </asp:ListItem>
                <asp:ListItem Value="40"> $ 40 </asp:ListItem>
                <asp:ListItem Value="50"> $ 50 </asp:ListItem>
                <asp:ListItem Value="60"> $ 60 </asp:ListItem>
            </asp:CheckBoxList>
        </div>
        <div>

            <asp:Button ID="Button1" runat="server" Text="Sum Up and Submit" OnClick="ItemSumSub" />
        </div>
        <asp:Label ID="Label1" runat="server" Text="Total : "></asp:Label>
    </form>
</body>
</html>
