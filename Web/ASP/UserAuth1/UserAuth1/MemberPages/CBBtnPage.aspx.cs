using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace UserAuth1.MemberPages
{
    public partial class CBBtnPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // this.Form.Target = "_blank";
            BtnHandle.Enabled = false;
        }

        protected void OnBtn_Click(object sender, EventArgs e)
        {
            var url = String.Format(@"CrazyPage.aspx");

            Response.Write("<script> window.open( '" + url + "','_parent' ); </script>");
            Response.End();
        }
    }
}