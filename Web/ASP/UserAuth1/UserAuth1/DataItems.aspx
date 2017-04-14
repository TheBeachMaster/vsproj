<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="DataItems.aspx.cs" Inherits="UserAuth1.DataItems" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Arthur's Super Awesome Caffe</title>
    
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
            <h2>Welcome to Arthur's Magical Caffe</h2>
            <asp:CheckBoxList ID="FoodItemsList" runat="server" OnSelectedIndexChanged="GetTotals">

            </asp:CheckBoxList>

        </div>
        <div class="container">
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Button ID="BtnSubmit" runat="server" Height="34px" Text="Submit Order" Width="152px" CssClass="btn btn-lg btn-primary" OnClick="AddItems" />

        </div>
        <div class="container">
            <asp:Label ID="TotalsLabel" runat="server" Text="Total : "></asp:Label>
        </div>
    </form>
</body>
</html>
