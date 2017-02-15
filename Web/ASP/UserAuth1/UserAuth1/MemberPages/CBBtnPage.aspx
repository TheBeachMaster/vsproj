<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="CBBtnPage.aspx.cs" Inherits="UserAuth1.MemberPages.CBBtnPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Check Box Button Page</title>
</head>
<body>
    <script language="C#" runat="server">
        
        bool handle = false;
      
        

        void CBOn_Click(Object sender, EventArgs e)
        {
            
          Message.Text="You have decided to :";

            if (myCbox.Items[0].Selected)
            {
                Message.Text = Message.Text + myCbox.Items[0].Text + "<br />";
                handle = true;
            }
        }

          protected void OnBtn_Click(object sender, EventArgs e)
        {
            if (handle)
            {

                Response.Redirect("CrazyPage.aspx");
            }
        }
        

    </script>
    <form id="form1" runat="server" action="CBBtnPage.aspx" method="post">
        <div>
            
       <asp:CheckBoxList id="myCbox" runat="server"
            AutoPostBack="True"
            CellPadding="5"
            CellSpacing="5"
            RepeatColumns="2"
            RepeatDirection="Vertical"
            RepeatLayout="Flow"
            TextAlign="Right"
            OnSelectedIndexChanged="CBOn_Click">

          <asp:ListItem>Take Me to Crazy Page</asp:ListItem>

       </asp:CheckBoxList>
            <br />
        </div>
        
        <asp:Button ID="Button1" runat="server" Text="Go to Page" Width="109px" OnClick="OnBtn_Click" />
        
       <br /><br />
       <asp:label id="Message" runat="server"/>
    </form>
</body>
</html>
