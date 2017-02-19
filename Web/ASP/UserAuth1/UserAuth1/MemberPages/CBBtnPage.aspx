<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="CBBtnPage.aspx.cs" Inherits="UserAuth1.MemberPages.CBBtnPage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Check Box Button Page</title>
</head>
<body>

    
          
            <!--if (myCbox.Items[0].Selected)
            //{
            //    Message.Text = Message.Text + myCbox.Items[0].Text + "<br />";
            //    BtnHandle.Enabled = true;

            //}
    -->
    
    <script language="C#" runat="server">

        void CBOn_Click(Object sender, EventArgs e)
        {
            Message.Text="You have decided to :";
            int a = myCbox.Items.Count;
            int count = 0;

            for (int i = 0; i < a; i++)
            {
                if (myCbox.Items[i].Selected == true)
                {
                    BtnHandle.Enabled = true;
                    Message.Text = Message.Text + myCbox.Items[0].Text + "<br />";
                    count++;
                    
                }
            }
            if (count > 1)
            {
                for (int i = 0; i < a; i++)
                {
                    if (myCbox.Items[i].Selected == true)
                    {
                        
                        myCbox.Items[i].Selected = false;
                        break;
                    }
                }
            }


        }


    </script>
    <form id="form1" runat="server" action="CBBtnPage.aspx" method="post">
        <div>
       <asp:CheckBoxList  id="myCbox" runat="server"
            AutoPostBack="True"
            CellPadding="5"
            CellSpacing="5"
            RepeatColumns="2"
            RepeatDirection="Vertical"
            RepeatLayout="Flow"
            TextAlign="Right"
           OnSelectedIndexChanged="CBOn_Click">

          <asp:ListItem Value="CrazyPage.aspx" >Take Me to Crazy Page</asp:ListItem>
           
          <asp:ListItem Value="Members.aspx">Take Me to Members Page</asp:ListItem>
           
          <asp:ListItem Value="AnotherPage.aspx">Take Me to Other Page</asp:ListItem>
           

       </asp:CheckBoxList>
            <br />
        </div>
        
        <asp:Button ID="BtnHandle" runat="server" Text="Go to Page" Width="109px" OnClick="OnBtn_Click" />
        
       <br /><br />
       <asp:label id="Message" runat="server"/>
    </form>
</body>
</html>
