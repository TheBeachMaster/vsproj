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
            String cbVal = "";
            //cbVal = myCbox.Items[0].Value + "";

            foreach (ListItem item in myCbox.Items)
            {
                if (item.Selected)
                {
                    cbVal += item.Value + "";
                }
            }

            Response.Write("<script> window.open( '" + cbVal + "','_parent' ); </script>");
            Response.End();
        }
    }
}