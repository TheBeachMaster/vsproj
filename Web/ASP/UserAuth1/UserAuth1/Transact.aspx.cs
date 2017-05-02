using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace UserAuth1
{
    public partial class Transact : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void LaunchPayModal(object sender, EventArgs e)
        {
            lblModalTitle.Text = "Validation Errors List for HP7 Citation";
            lblModalBody.Text = "This is modal body";
            ScriptManager.RegisterStartupScript(Page, Page.GetType(), "transactModal", "$('#transactModal').modal();", true);
            upModal.Update();
        }
    }
}