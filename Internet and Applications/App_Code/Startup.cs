using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(www71.Startup))]
namespace www71
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
