<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="CheckBox.aspx.cs" Inherits="UserAuth1.MemberPages.CheckBox" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>ASP.NET Example</title>
</head>
 <body>
    <script language="C#" runat="server">
       void Check_Clicked(Object sender, EventArgs e) {
          Message.Text="Selected Item(s):" + "<br />" + "<br />";
          for (int i=0; i<checkboxlist1.Items.Count; i++) {
             if (checkboxlist1.Items[i].Selected)
                Message.Text=Message.Text + checkboxlist1.Items[i].Text + "<br />";
          }
       }
    </script>

    <form id="form1" action="CheckBox.aspx" method="post" runat="server">

       <asp:CheckBoxList id="checkboxlist1" runat="server"
            AutoPostBack="True"
            CellPadding="5"
            CellSpacing="5"
            RepeatColumns="2"
            RepeatDirection="Vertical"
            RepeatLayout="Flow"
            TextAlign="Right"
            OnSelectedIndexChanged="Check_Clicked">

          <asp:ListItem>Item 1</asp:ListItem>
          <asp:ListItem>Item 2</asp:ListItem>
          <asp:ListItem>Item 3</asp:ListItem>
          <asp:ListItem>Item 4</asp:ListItem>
          <asp:ListItem>Item 5</asp:ListItem>
          <asp:ListItem>Item 6</asp:ListItem>

       </asp:CheckBoxList>

       <br /><br />
       <asp:label id="Message" runat="server"/>

    </form>

 </body>
</html>
