<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Menus.aspx.cs" Inherits="UserAuth1.Menus" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>The Kibandaski Network</title>


    <link href="Contents/bootstrap-theme.min.css" rel="stylesheet" />
    <link href="Contents/bootstrap.min.css" rel="stylesheet" />

</head>
<body>

    <script src="Scripts/jquery.min.js" type="text/javascript"></script>
    <script src="Scripts/bootstrap.min.js" type="text/javascript"></script>

    <form id="form1" runat="server">
        <asp:ScriptManager ID="ScriptManager2" runat="server">
        </asp:ScriptManager>

        <div class="container-fluid" id="restaurantlist">

            <h3>Select a Restaurant from the list below</h3>

            <div class="container">

                <asp:CheckBoxList ID="RestaurantList" runat="server">
                </asp:CheckBoxList>
            </div>

            <div class="center">
                <asp:Button ID="RestSelBtn" runat="server" Text="Submit" CssClass="btn btn-lg btn-primary" />
            </div>

        </div>

        <div class="container-fluid center" id="menulist" >
            <asp:Label ID="RestLabel" runat="server"></asp:Label>
            <br />

            <div id="breakfast">

                <h3>Breakfast</h3>
                <asp:CheckBoxList ID="CheckBoxList1" runat="server"></asp:CheckBoxList>

                <hr />
            </div>
            <div id="lunch">
                <h3>Lunch</h3>
                <asp:CheckBoxList ID="LunchList" runat="server"></asp:CheckBoxList>
                <hr />
            </div>
            <div id="supper">
                <h3>Supper
                </h3>
                <asp:CheckBoxList ID="SupperlIst" runat="server"></asp:CheckBoxList>
                <hr />
            </div>
        </div>

    </form>
</body>
</html>
