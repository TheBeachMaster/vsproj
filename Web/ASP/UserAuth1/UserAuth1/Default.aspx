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
            <asp:LoginView ID="LoginView1" runat="server">
                <AnonymousTemplate>
                   <h3>You are not Logged in.Please login to continue</h3>&nbsp;
                </AnonymousTemplate>
                <LoggedInTemplate>
                    You&#39;re logged In.Welcome&nbsp;
                    <asp:LoginName ID="LoginName1" runat="server"  />
                    &nbsp;
                </LoggedInTemplate>
            </asp:LoginView>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:LoginStatus ID="LoginStatus1" runat="server" LogoutAction="RedirectToLoginPage"  LogoutPageUrl="~/Login.aspx" OnLoggingOut="LoginStatus1_LoggingOut" />
        </div>

        <div>

            <br />
            <br />
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/MemberPages/Members.aspx">Go to Member Page</asp:HyperLink>

        </div>
    </form>
</body>
</html>
