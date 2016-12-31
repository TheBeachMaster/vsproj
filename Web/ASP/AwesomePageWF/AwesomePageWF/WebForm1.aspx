<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="AwesomePageWF.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Awesome Page</title>
    <style>
        div {
            background :url("assets/barlink.png");
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>

            Welcome to Your Awesome Webforms Page<br />
            <br />
            Enter Details:<br />
            Name:<br />
            <asp:TextBox ID="TBName" runat="server"></asp:TextBox>
&nbsp;&nbsp;
            <br />
            Age:&nbsp;
            <br />
            <asp:TextBox ID="TBAge" runat="server"></asp:TextBox>
            <br />
            <br />
&nbsp;<asp:Button ID="BtnShow" runat="server" OnClick="BtnShow_Click" Text="Show Details" Width="111px" />
            <br />
            <br />
            <asp:Label ID="DtlLabel" runat="server" ForeColor="Red" Text="Label"></asp:Label>
            <br />

        </div>
    </form>
</body>
</html>
