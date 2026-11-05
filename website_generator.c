/**
 * ============================================================================
 * Project: Industrial Gas Capture & Utilization (IGCU)
 * Program: website_generator.c
 * Purpose: Generates the complete, modern, responsive website HTML file
 *          from structured C data and templates.
 *
 * Compilation:
 *   gcc website_generator.c -o website_generator
 *   (or cl website_generator.c on MSVC)
 *
 * Execution:
 *   ./website_generator
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for Target Gases */
typedef struct {
    const char *symbol;
    const char *name;
    const char *concern;
    const char *css_class;
} TargetGas;

/* Structure for System Cycle Stages */
typedef struct {
    int step;
    const char *title;
    const char *description;
} ProcessStep;

int main(void) {
    printf("========================================================\n");
    printf(" Industrial Gas Capture & Utilization Website Generator \n");
    printf("========================================================\n");
    printf("Generating 'index.html'...\n");

    FILE *fp = fopen("index.html", "w");
    if (!fp) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    /* Target Gases Array based on Slide 4 */
    TargetGas gases[] = {
        {"CO2",  "Carbon Dioxide",             "Major Greenhouse gas & global warming driver", "co2"},
        {"NOx",  "Nitrogen Oxides",            "Smog precursor & severe air pollution",        "nox"},
        {"SOx",  "Sulfur Oxides",              "Acid rain formation & respiratory irritation", "sox"},
        {"CO",   "Carbon Monoxide",            "Lethal toxic asphyxiant chemical compound",    "co"},
        {"VOCs", "Volatile Organic Compounds", "Ground ozone trigger & hazardous vapors",      "voc"}
    };
    int total_gases = sizeof(gases) / sizeof(gases[0]);

    /* Process Stages based on Slide 7 */
    ProcessStep steps[] = {
        {1, "Industrial Process", "Combustion & kiln exhaust emission point"},
        {2, "Emission Capture",   "Electrostatic precipitators & hoods"},
        {3, "Gas Separation",     "Membranes & cryogenic fractionators"},
        {4, "Purification",       "Multi-stage catalytic & adsorption beds"},
        {5, "Safe Storage",       "Pressure-rated ASME containment tanks"},
        {6, "Conversion",         "Catalytic reactors & mineralization"},
        {7, "Useful Products",    "Fuels, fertilizers, acids & concrete"}
    };
    int total_steps = sizeof(steps) / sizeof(steps[0]);

    /* Write HTML Header & CSS */
    fprintf(fp, "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n");
    fprintf(fp, "  <meta charset=\"UTF-8\">\n");
    fprintf(fp, "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(fp, "  <title>Industrial Gas Capture & Utilization</title>\n");
    fprintf(fp, "  <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">\n");
    fprintf(fp, "  <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>\n");
    fprintf(fp, "  <link href=\"https://fonts.googleapis.com/css2?family=Plus+Jakarta+Sans:wght@300;400;600;700;800&family=JetBrains+Mono:wght@400;700&display=swap\" rel=\"stylesheet\">\n");
    fprintf(fp, "  <style>\n");
    fprintf(fp, "    :root {\n");
    fprintf(fp, "      --bg-dark: #090d16;\n");
    fprintf(fp, "      --bg-card: rgba(18, 24, 38, 0.85);\n");
    fprintf(fp, "      --border-color: rgba(255, 255, 255, 0.08);\n");
    fprintf(fp, "      --border-glow: rgba(0, 210, 255, 0.3);\n");
    fprintf(fp, "      --text-main: #f1f5f9;\n");
    fprintf(fp, "      --text-muted: #94a3b8;\n");
    fprintf(fp, "      --cyan-accent: #00d2ff;\n");
    fprintf(fp, "      --green-accent: #00e676;\n");
    fprintf(fp, "      --amber-accent: #fbbf24;\n");
    fprintf(fp, "      --red-accent: #f87171;\n");
    fprintf(fp, "      --purple-accent: #a855f7;\n");
    fprintf(fp, "      --font-main: 'Plus Jakarta Sans', sans-serif;\n");
    fprintf(fp, "      --font-mono: 'JetBrains Mono', monospace;\n");
    fprintf(fp, "    }\n");
    fprintf(fp, "    * { box-sizing: border-box; margin: 0; padding: 0; scroll-behavior: smooth; }\n");
    fprintf(fp, "    body {\n");
    fprintf(fp, "      background-color: var(--bg-dark);\n");
    fprintf(fp, "      color: var(--text-main);\n");
    fprintf(fp, "      font-family: var(--font-main);\n");
    fprintf(fp, "      line-height: 1.6;\n");
    fprintf(fp, "      background-image: radial-gradient(circle at 15%% 20%%, rgba(0, 210, 255, 0.08) 0%%, transparent 40%%), radial-gradient(circle at 85%% 75%%, rgba(0, 230, 118, 0.07) 0%%, transparent 45%%);\n");
    fprintf(fp, "    }\n");
    fprintf(fp, "    .container { max-width: 1200px; margin: 0 auto; padding: 0 24px; }\n");
    fprintf(fp, "    header { position: sticky; top: 0; z-index: 100; background: rgba(9, 13, 22, 0.9); backdrop-filter: blur(12px); border-bottom: 1px solid var(--border-color); }\n");
    fprintf(fp, "    .nav-inner { display: flex; justify-content: space-between; align-items: center; padding: 16px 0; }\n");
    fprintf(fp, "    .logo { display: flex; align-items: center; gap: 10px; font-weight: 800; font-size: 1.15rem; color: #fff; text-decoration: none; }\n");
    fprintf(fp, "    .logo-badge { width: 34px; height: 34px; border-radius: 8px; background: linear-gradient(135deg, #00d2ff, #00e676); display: flex; align-items: center; justify-content: center; color: #090d16; font-weight: 900; }\n");
    fprintf(fp, "    .nav-links { display: flex; gap: 24px; list-style: none; }\n");
    fprintf(fp, "    .nav-links a { color: var(--text-muted); text-decoration: none; font-size: 0.9rem; font-weight: 500; transition: color 0.2s; }\n");
    fprintf(fp, "    .nav-links a:hover { color: var(--cyan-accent); }\n");
    fprintf(fp, "    section { padding: 65px 0; border-top: 1px solid var(--border-color); }\n");
    fprintf(fp, "    .hero { text-align: center; padding: 80px 0 50px; border-top: none; }\n");
    fprintf(fp, "    .badge-tag { display: inline-flex; align-items: center; gap: 8px; background: rgba(0, 210, 255, 0.1); border: 1px solid rgba(0, 210, 255, 0.3); padding: 6px 16px; border-radius: 999px; color: var(--cyan-accent); font-size: 0.85rem; font-weight: 600; text-transform: uppercase; margin-bottom: 20px; }\n");
    fprintf(fp, "    .hero h1 { font-size: clamp(2.2rem, 5vw, 3.5rem); font-weight: 800; line-height: 1.15; max-width: 900px; margin: 0 auto 20px; }\n");
    fprintf(fp, "    .gradient-text { background: linear-gradient(135deg, #ffffff 30%%, #00d2ff 75%%, #00e676 100%%); -webkit-background-clip: text; -webkit-text-fill-color: transparent; }\n");
    fprintf(fp, "    .hero-subtitle { font-size: 1.2rem; color: var(--text-muted); max-width: 700px; margin: 0 auto 35px; }\n");
    fprintf(fp, "    .pillar-row { display: flex; justify-content: center; gap: 14px; flex-wrap: wrap; }\n");
    fprintf(fp, "    .pillar-pill { background: rgba(255, 255, 255, 0.04); border: 1px solid var(--border-color); padding: 8px 20px; border-radius: 30px; font-size: 0.9rem; font-weight: 600; }\n");
    fprintf(fp, "    .section-header { margin-bottom: 40px; }\n");
    fprintf(fp, "    .section-num { font-family: var(--font-mono); color: var(--cyan-accent); font-size: 0.85rem; font-weight: 700; letter-spacing: 2px; text-transform: uppercase; display: block; margin-bottom: 6px; }\n");
    fprintf(fp, "    .section-title { font-size: 1.9rem; font-weight: 700; letter-spacing: -0.5px; }\n");
    fprintf(fp, "    .section-desc { color: var(--text-muted); max-width: 600px; font-size: 0.95rem; margin-top: 6px; }\n");
    fprintf(fp, "    .grid-2 { display: grid; grid-template-columns: repeat(auto-fit, minmax(320px, 1fr)); gap: 20px; }\n");
    fprintf(fp, "    .grid-3 { display: grid; grid-template-columns: repeat(auto-fit, minmax(280px, 1fr)); gap: 20px; }\n");
    fprintf(fp, "    .grid-5 { display: grid; grid-template-columns: repeat(auto-fit, minmax(200px, 1fr)); gap: 16px; }\n");
    fprintf(fp, "    .card { background: var(--bg-card); border: 1px solid var(--border-color); border-radius: 14px; padding: 24px; transition: transform 0.2s, border-color 0.2s; }\n");
    fprintf(fp, "    .card:hover { transform: translateY(-4px); border-color: var(--border-glow); }\n");
    fprintf(fp, "    .gas-badge { font-family: var(--font-mono); font-size: 1.3rem; font-weight: 800; padding: 6px 12px; border-radius: 8px; display: inline-block; margin-bottom: 12px; }\n");
    fprintf(fp, "    .gas-badge.co2 { background: rgba(59, 130, 246, 0.2); border: 1px solid #3b82f6; color: #93c5fd; }\n");
    fprintf(fp, "    .gas-badge.nox { background: rgba(239, 68, 68, 0.2); border: 1px solid #ef4444; color: #fca5a5; }\n");
    fprintf(fp, "    .gas-badge.sox { background: rgba(245, 158, 11, 0.2); border: 1px solid #f59e0b; color: #fcd34d; }\n");
    fprintf(fp, "    .gas-badge.co  { background: rgba(168, 85, 247, 0.2); border: 1px solid #a855f7; color: #d8b4fe; }\n");
    fprintf(fp, "    .gas-badge.voc { background: rgba(16, 185, 129, 0.2); border: 1px solid #10b981; color: #6ee7b7; }\n");
    fprintf(fp, "    .process-timeline { display: grid; grid-template-columns: repeat(auto-fit, minmax(140px, 1fr)); gap: 12px; margin-top: 20px; }\n");
    fprintf(fp, "    .process-card { background: var(--bg-card); border: 1px solid var(--border-color); border-radius: 10px; padding: 16px 12px; text-align: center; }\n");
    fprintf(fp, "    .step-badge { width: 30px; height: 30px; background: rgba(0, 210, 255, 0.15); color: var(--cyan-accent); border-radius: 50%%; margin: 0 auto 10px; display: flex; align-items: center; justify-content: center; font-weight: 700; font-size: 0.85rem; }\n");
    fprintf(fp, "    .calc-box { background: var(--bg-card); border: 1px solid var(--border-glow); border-radius: 16px; padding: 30px; margin-top: 20px; }\n");
    fprintf(fp, "    .calc-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 30px; }\n");
    fprintf(fp, "    @media(max-width:768px){ .calc-grid { grid-template-columns: 1fr; } .nav-links { display: none; } }\n");
    fprintf(fp, "    .slider-group { margin-bottom: 20px; }\n");
    fprintf(fp, "    .slider-header { display: flex; justify-content: space-between; margin-bottom: 6px; font-weight: 600; font-size: 0.9rem; }\n");
    fprintf(fp, "    input[type=range] { width: 100%%; accent-color: var(--cyan-accent); }\n");
    fprintf(fp, "    .results-display { background: rgba(255, 255, 255, 0.02); border: 1px solid var(--border-color); border-radius: 12px; padding: 20px; display: flex; flex-direction: column; gap: 14px; }\n");
    fprintf(fp, "    .metric-row { display: flex; justify-content: space-between; align-items: center; border-bottom: 1px solid rgba(255,255,255,0.05); padding-bottom: 10px; }\n");
    fprintf(fp, "    .metric-value { font-family: var(--font-mono); font-size: 1.25rem; font-weight: 700; color: var(--green-accent); }\n");
    fprintf(fp, "    .alert-box { background: rgba(245, 158, 11, 0.08); border: 1px solid rgba(245, 158, 11, 0.3); border-radius: 10px; padding: 16px 20px; margin-top: 20px; display: flex; gap: 14px; }\n");
    fprintf(fp, "    footer { border-top: 1px solid var(--border-color); padding: 40px 0; text-align: center; color: var(--text-muted); font-size: 0.9rem; }\n");
    fprintf(fp, "    .c-badge { display: inline-block; background: rgba(0, 210, 255, 0.1); border: 1px solid rgba(0, 210, 255, 0.25); padding: 4px 12px; border-radius: 6px; font-family: var(--font-mono); font-size: 0.8rem; color: var(--cyan-accent); margin-top: 12px; }\n");
    fprintf(fp, "  </style>\n</head>\n<body>\n");

    /* Header */
    fprintf(fp, "  <header>\n    <div class=\"container nav-inner\">\n");
    fprintf(fp, "      <a href=\"#\" class=\"logo\"><div class=\"logo-badge\">⚡</div><span>IGCU System</span></a>\n");
    fprintf(fp, "      <ul class=\"nav-links\">\n");
    fprintf(fp, "        <li><a href=\"#problem\">Problem</a></li>\n");
    fprintf(fp, "        <li><a href=\"#concept\">Concept</a></li>\n");
    fprintf(fp, "        <li><a href=\"#gases\">Target Gases</a></li>\n");
    fprintf(fp, "        <li><a href=\"#cycle\">Cycle</a></li>\n");
    fprintf(fp, "        <li><a href=\"#calculator\">Simulator</a></li>\n");
    fprintf(fp, "        <li><a href=\"#future\">Future Scope</a></li>\n");
    fprintf(fp, "      </ul>\n    </div>\n  </header>\n\n");

    /* Hero Section (Slide 1) */
    fprintf(fp, "  <section class=\"hero\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"badge-tag\">🌱 Eco-Industrial Engineering Project</div>\n");
    fprintf(fp, "      <h1>INDUSTRIAL GAS <span class=\"gradient-text\">CAPTURE & UTILIZATION</span></h1>\n");
    fprintf(fp, "      <p class=\"hero-subtitle\">Transforming Toxic Industrial Emissions into Valuable Resources.</p>\n");
    fprintf(fp, "      <div class=\"pillar-row\">\n");
    fprintf(fp, "        <div class=\"pillar-pill\">🌿 Cleaner Environment</div>\n");
    fprintf(fp, "        <div class=\"pillar-pill\">🏭 Sustainable Industry</div>\n");
    fprintf(fp, "        <div class=\"pillar-pill\">✨ A Brighter Future</div>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Slide 2: The Problem */
    fprintf(fp, "  <section id=\"problem\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">01 / The Challenge</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">Industrial Emissions: An Invisible Threat</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">Conventional pollution-control methods focus on disposal and chimney venting rather than capture and utilization.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"grid-3\">\n");
    fprintf(fp, "        <div class=\"card\"><h3 style=\"color:var(--red-accent);margin-bottom:8px;\">Gaseous Pollutants</h3><p style=\"color:var(--text-muted);font-size:0.9rem;\">Industries release vast volumes of harmful gases into the atmosphere daily.</p></div>\n");
    fprintf(fp, "        <div class=\"card\"><h3 style=\"color:var(--amber-accent);margin-bottom:8px;\">Environmental Toll</h3><p style=\"color:var(--text-muted);font-size:0.9rem;\">Major drivers of climate disruption, respiratory illness, and acid rain.</p></div>\n");
    fprintf(fp, "        <div class=\"card\"><h3 style=\"color:var(--cyan-accent);margin-bottom:8px;\">Missing Link</h3><p style=\"color:var(--text-muted);font-size:0.9rem;\">Traditional scrubbers treat valuable chemical building blocks as discardable waste.</p></div>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Slide 3 & 10: Concept & Circular Model */
    fprintf(fp, "  <section id=\"concept\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">02 / Paradigm</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">Our Concept: From Emission to Resource</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">Safely contain emissions at the source and convert them into valuable products.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"grid-2\">\n");
    fprintf(fp, "        <div class=\"card\" style=\"border-color:rgba(239,68,68,0.3);\">\n");
    fprintf(fp, "          <h3 style=\"color:var(--red-accent);margin-bottom:12px;\">✕ Traditional Linear Approach</h3>\n");
    fprintf(fp, "          <p style=\"color:var(--text-muted);\">Industry &rarr; Raw Emission &rarr; Atmosphere &rarr; Pollution</p>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "        <div class=\"card\" style=\"border-color:rgba(0,230,118,0.3);\">\n");
    fprintf(fp, "          <h3 style=\"color:var(--green-accent);margin-bottom:12px;\">✓ Circular Economy Approach</h3>\n");
    fprintf(fp, "          <p style=\"color:var(--text-muted);\">Industry &rarr; Capture &rarr; Purification &rarr; Conversion &rarr; Useful Products</p>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Slide 4: Target Industrial Gases (Iterating through C Array) */
    fprintf(fp, "  <section id=\"gases\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">03 / Target Compounds</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">What Are We Capturing?</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">Targeted industrial gases and their major atmospheric hazards.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"grid-5\">\n");

    for (int i = 0; i < total_gases; i++) {
        fprintf(fp, "        <div class=\"card\">\n");
        fprintf(fp, "          <div class=\"gas-badge %s\">%s</div>\n", gases[i].css_class, gases[i].symbol);
        fprintf(fp, "          <h4 style=\"margin-bottom:6px;\">%s</h4>\n", gases[i].name);
        fprintf(fp, "          <p style=\"color:var(--text-muted);font-size:0.85rem;\">%s</p>\n", gases[i].concern);
        fprintf(fp, "        </div>\n");
    }
    fprintf(fp, "      </div>\n");

    /* Slide 6 Important Warning */
    fprintf(fp, "      <div class=\"alert-box\">\n");
    fprintf(fp, "        <div style=\"font-size:1.4rem;\">⚠️</div>\n");
    fprintf(fp, "        <div>\n");
    fprintf(fp, "          <strong style=\"color:var(--amber-accent);\">Crucial Safety Protocol:</strong>\n");
    fprintf(fp, "          <p style=\"color:var(--text-muted);font-size:0.85rem;margin-top:4px;\">These gases should NOT simply be stored together. Each pollutant requires a gas-specific capture, purification, containment and conversion process.</p>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Slide 7: Recovery Cycle (Iterating through C Array) */
    fprintf(fp, "  <section id=\"cycle\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">04 / Recovery Pipeline</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">How the System Works</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">The 7-stage closed-loop industrial gas recovery cycle.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"process-timeline\">\n");

    for (int i = 0; i < total_steps; i++) {
        fprintf(fp, "        <div class=\"process-card\">\n");
        fprintf(fp, "          <div class=\"step-badge\">%d</div>\n", steps[i].step);
        fprintf(fp, "          <h4 style=\"font-size:0.9rem;margin-bottom:4px;\">%s</h4>\n", steps[i].title);
        fprintf(fp, "          <p style=\"color:var(--text-muted);font-size:0.75rem;\">%s</p>\n", steps[i].description);
        fprintf(fp, "        </div>\n");
    }
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Slide 8: Safe Storage */
    fprintf(fp, "  <section id=\"storage\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">05 / Containment Standards</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">Safe Storage Engineering</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">How captured industrial gases are securely contained.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"grid-2\">\n");
    fprintf(fp, "        <div class=\"card\">\n");
    fprintf(fp, "          <h3 style=\"color:var(--cyan-accent);margin-bottom:10px;\">Pressure-Rated Containment</h3>\n");
    fprintf(fp, "          <p style=\"color:var(--text-muted);font-size:0.9rem;\">Use engineered pressure-rated containment systems appropriate to each specific gas. Maintain controlled temperature and pressure conditions continuously.</p>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "        <div class=\"card\">\n");
    fprintf(fp, "          <h3 style=\"color:var(--green-accent);margin-bottom:10px;\">Automated Monitoring</h3>\n");
    fprintf(fp, "          <p style=\"color:var(--text-muted);font-size:0.9rem;\">Continuous monitoring for leaks, pressure fluctuations, and corrosion. Strict compliance with industrial safety and environmental standards.</p>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Interactive Simulator */
    fprintf(fp, "  <section id=\"calculator\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">06 / Yield Simulator</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">Gas Recovery & Value Estimator</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">Simulate plant emissions and forecast resource generation.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"calc-box\">\n");
    fprintf(fp, "        <div class=\"calc-grid\">\n");
    fprintf(fp, "          <div>\n");
    fprintf(fp, "            <div class=\"slider-group\">\n");
    fprintf(fp, "              <div class=\"slider-header\"><span>Flue Gas (Tons/Day):</span><span id=\"flueVal\" style=\"color:var(--cyan-accent);\">500 Tons</span></div>\n");
    fprintf(fp, "              <input type=\"range\" id=\"flueSlider\" min=\"50\" max=\"2000\" step=\"50\" value=\"500\" oninput=\"calc()\">\n");
    fprintf(fp, "            </div>\n");
    fprintf(fp, "            <div class=\"slider-group\">\n");
    fprintf(fp, "              <div class=\"slider-header\"><span>Capture Efficiency (%%):</span><span id=\"effVal\" style=\"color:var(--green-accent);\">85 %%</span></div>\n");
    fprintf(fp, "              <input type=\"range\" id=\"effSlider\" min=\"60\" max=\"98\" step=\"1\" value=\"85\" oninput=\"calc()\">\n");
    fprintf(fp, "            </div>\n");
    fprintf(fp, "          </div>\n");
    fprintf(fp, "          <div class=\"results-display\">\n");
    fprintf(fp, "            <div class=\"metric-row\"><span>Net CO₂ Recovered:</span><span class=\"metric-value\" id=\"netCo2\">59.5 T/d</span></div>\n");
    fprintf(fp, "            <div class=\"metric-row\"><span>Synthetic Products:</span><span class=\"metric-value\" id=\"prodOut\" style=\"color:var(--cyan-accent);\">43.2 T/d</span></div>\n");
    fprintf(fp, "            <div class=\"metric-row\"><span>Estimated Daily Value:</span><span class=\"metric-value\" id=\"valOut\" style=\"color:var(--green-accent);\">$23,800</span></div>\n");
    fprintf(fp, "          </div>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Slide 11 & 12: Challenges & Future Scope */
    fprintf(fp, "  <section id=\"future\">\n    <div class=\"container\">\n");
    fprintf(fp, "      <div class=\"section-header\">\n");
    fprintf(fp, "        <span class=\"section-num\">07 / Horizon</span>\n");
    fprintf(fp, "        <h2 class=\"section-title\">Challenges & Future Scope</h2>\n");
    fprintf(fp, "        <p class=\"section-desc\">Engineering the next generation of emission management.</p>\n");
    fprintf(fp, "      </div>\n");
    fprintf(fp, "      <div class=\"grid-2\">\n");
    fprintf(fp, "        <div class=\"card\">\n");
    fprintf(fp, "          <h3 style=\"color:var(--amber-accent);margin-bottom:12px;\">Key Challenges</h3>\n");
    fprintf(fp, "          <ul style=\"color:var(--text-muted);list-style-position:inside;font-size:0.9rem;line-height:1.8;\">\n");
    fprintf(fp, "            <li>High energy requirements for desorption</li>\n");
    fprintf(fp, "            <li>Gas separation and ultra-pure purification</li>\n");
    fprintf(fp, "            <li>Safe long-term storage & infrastructure costs</li>\n");
    fprintf(fp, "            <li>Continuous risk management & monitoring</li>\n");
    fprintf(fp, "          </ul>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "        <div class=\"card\">\n");
    fprintf(fp, "          <h3 style=\"color:var(--cyan-accent);margin-bottom:12px;\">Future Scope</h3>\n");
    fprintf(fp, "          <ul style=\"color:var(--text-muted);list-style-position:inside;font-size:0.9rem;line-height:1.8;\">\n");
    fprintf(fp, "            <li>Advanced adsorption materials (MOFs)</li>\n");
    fprintf(fp, "            <li>Membrane-based low energy gas separation</li>\n");
    fprintf(fp, "            <li>AI-assisted predictive emission monitoring</li>\n");
    fprintf(fp, "            <li>Direct integration with renewable power</li>\n");
    fprintf(fp, "          </ul>\n");
    fprintf(fp, "        </div>\n");
    fprintf(fp, "      </div>\n");

    /* Slide 13: Conclusion */
    fprintf(fp, "      <div class=\"card\" style=\"text-align:center;margin-top:24px;border-color:rgba(0,230,118,0.3);\">\n");
    fprintf(fp, "        <h2 style=\"margin-bottom:10px;\">\"Waste Gases Can Become Resources.\"</h2>\n");
    fprintf(fp, "        <p style=\"color:var(--text-muted);max-width:750px;margin:0 auto;\">The objective is not merely to prevent industrial emissions from entering the atmosphere, but to develop a closed-loop system where harmful gases are captured, safely managed, and transformed into useful resources.</p>\n");
    fprintf(fp, "      </div>\n    </div>\n  </section>\n\n");

    /* Footer & JS */
    fprintf(fp, "  <footer>\n    <div class=\"container\">\n");
    fprintf(fp, "      <p>Industrial Gas Capture & Utilization Project</p>\n");
    fprintf(fp, "      <span class=\"c-badge\">⚡ Generated via C Program (website_generator.c)</span>\n");
    fprintf(fp, "    </div>\n  </footer>\n");

    fprintf(fp, "  <script>\n");
    fprintf(fp, "    function calc(){\n");
    fprintf(fp, "      var flue = parseFloat(document.getElementById('flueSlider').value);\n");
    fprintf(fp, "      var eff = parseFloat(document.getElementById('effSlider').value);\n");
    fprintf(fp, "      document.getElementById('flueVal').innerText = flue + ' Tons';\n");
    fprintf(fp, "      document.getElementById('effVal').innerText = eff + ' %%';\n");
    fprintf(fp, "      var co2 = flue * 0.14 * (eff / 100.0);\n");
    fprintf(fp, "      var prod = co2 * 0.727;\n");
    fprintf(fp, "      var val = (prod * 380) + (co2 * 85);\n");
    fprintf(fp, "      document.getElementById('netCo2').innerText = co2.toFixed(1) + ' T/d';\n");
    fprintf(fp, "      document.getElementById('prodOut').innerText = prod.toFixed(1) + ' T/d';\n");
    fprintf(fp, "      document.getElementById('valOut').innerText = '$' + Math.round(val).toLocaleString();\n");
    fprintf(fp, "    }\n");
    fprintf(fp, "    calc();\n");
    fprintf(fp, "  </script>\n");
    fprintf(fp, "</body>\n</html>\n");

    fclose(fp);
    printf("Successfully generated 'index.html'!\n");
    return EXIT_SUCCESS;
}
