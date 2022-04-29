"""
FILE: AnalysisTemplate.py
INFO: Parametric analysis for a specified contact model
NOTE: Contact model settings are defined in file 'Params.f3fis' and file 'MemGen.p3dat'
AUTHOR: Wanghao
DATE: 2022.04.28
"""
import os
import shutil
import itasca as it
it.command("python-reset-state false")

def full_csv_name():
    for test in os.listdir('./ret/'):
        for ret in os.listdir('./ret/' + test):
            if ret == 'result.sav':
                it.command(f"""
                model restore './ret/{test}/{ret}'
                ;plot 'Result' export csv filename [save_dir + test_name + '.csv']
                """)
                src = os.path.join('.', 'ret', test, it.fish.get('test_name') + '.csv')
                dst = os.path.join('.', 'csv', it.fish.get('test_name') + '.csv')
                shutil.copy(src, dst)
#full_csv_name()

emods = []
krats = []
frics = []
rrfrs = []
emod, krat, fric, rrfr = 0.0, 0.0, 0.0, 0.0 # default value
ini_model = 'BalancedSpecimen.sav'

for emod in emods:
    it.command(f"""
    model restore {ini_model}
    
    [linEmod = {emod}]
    [linKrat = {krat}]
    [fric    = {fric}]
    [rrFric  = {rrfr}]
    
    [g_s = 1e5 ] ; overwrite
    [g_e = 1e-2] ; overwrite
    [mem_name = 'example_mem']
    [save_dir = './mem/' + mem_name + '_']
    program call 'MemGen.p3dat' suppress
    
    [load_rate = 5e-2]
    [test_name = 'example_test']
    program system ['mkdir ret\\\\' + test_name]
    [save_dir = './ret/' + test_name + '/']
    program call 'Test.p3dat' suppress
    
    project save [global.title + '.prj']
    program return
    """)
