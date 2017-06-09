package cn.cslg.CSLGAccessReservationSystem.Filter;


import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class LoginFilter implements Filter{

        private static final String LOGIN_URI = "LOGIN_URI";

        private String login_page;


        public void destroy() {
        }

        public void doFilter(ServletRequest request, ServletResponse response,
                FilterChain chain) throws IOException, ServletException {
            HttpServletRequest req = (HttpServletRequest) request;
            HttpServletResponse resp = (HttpServletResponse) response;
            resp.setContentType("text/html;");
            resp.setCharacterEncoding("utf-8");
            HttpSession session = req.getSession();
            // PrintWriter out = resp.getWriter();
            // 得到用户请求的URI
            String request_uri = req.getRequestURI();
            // 得到web应用程序的上下文路径
            String ctxPath = req.getContextPath();
            // 去除上下文路径，得到剩余部分的路径
            String uri = request_uri.substring(ctxPath.length());
            // 判断用户访问的是否是登录页面
            if (uri.equals(login_page)) {
                chain.doFilter(request, response);
                return;
            } else {
                // 如果访问的不是登录页面，则判断用户是否已经登录
                if (null != session.getAttribute("manager")
                        && "" != session.getAttribute("manager"))

                {
                    chain.doFilter(request, response);
                    return;
                }
                else {
                    resp.sendRedirect(req.getContextPath() + "/index.jsp");
                }
                //out.println("<script language=/"javaScript/">"
                // + "parent.location.href='" +

                //ctxPath + logon_page + "'"
                //  + "</script>");
                // return;
                // }
            }
        }

        public void init(FilterConfig config) throws ServletException {
            // TODO Auto-generated method stub
            // 从部署描述符中获取登录页面和首页的URI
            login_page = config.getInitParameter(LOGIN_URI);
            // System.out.println(logon_page);
            if (null == login_page) {
                throw new ServletException("没有找到登录页面或主页");
            }
        }

}