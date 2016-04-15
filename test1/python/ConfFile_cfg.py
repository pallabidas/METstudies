import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.load('Configuration.Geometry.GeometryRecoDB_cff')
process.GlobalTag.globaltag = '80X_mcRun2_asymptotic_2016_v3'

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#	'/store/mc/RunIISpring15FSPremix/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/MCRUN2_74_V9-v1/10000/0036D0D2-BC5F-E511-AEEB-00259073E4BE.root'
	'/store/relval/CMSSW_8_0_3/RelValProdTTbar_13/MINIAODSIM/80X_mcRun2_asymptotic_2016_v3_gs7120p2NewGTv3-v1/00000/607105FE-D0EF-E511-BBC0-0CC47A78A426.root'
    )
)

process.demo = cms.EDAnalyzer('test1',
    mets = cms.InputTag("slimmedMETs"),
)


process.p = cms.Path(process.demo)
#print process.dumpPython()
